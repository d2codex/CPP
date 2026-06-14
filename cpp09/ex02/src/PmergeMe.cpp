#include "../includes/PmergeMe.hpp"
#include <vector>
#include <deque>
#include <string>
#include <cctype>
#include <cerrno>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>
#include <iostream>
#include <utility>
#include <iomanip>

/**
 * @brief Default constructor.
 * Constructs an empty PmergeMe instance.
 */
PmergeMe::PmergeMe() {
}

/**
 * @brief Copy constructor (disabled behavior).
 * Copying is explicitly ignored; internal state is not duplicated.
 */
PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}
/**
 * @brief Copy assignment operator (disabled behavior).
 * Assignment does not copy internal state.
 * @return Reference to this object.
 */
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

/**
 * @brief Destructor.
 */
PmergeMe::~PmergeMe() {
}

/**
 * @brief Parses and validates program input.
 *
 * Converts command-line arguments into integer values stored in both
 * vector and deque containers.
 *
 * Validation steps:
 * - Ensures each token is a valid integer representation
 * - Checks for overflow using strtol
 * - Rejects non-numeric or partially numeric input
 * - Ensures values are unique (no duplicates)
 *
 * @note Duplicates are not allowed because the Ford–Johnson algorithm
 * assumes a strict pairing structure (a < b) where each element belongs
 * to exactly one pair. Duplicates would break this one-to-one mapping
 * and invalidate the pairing and insertion logic.
 *
 * @throws std::runtime_error on invalid input or duplicates
 * @throws std::out_of_range on integer overflow
 */
void PmergeMe::parseInput(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		std::string token;

		while (iss >> token)
		{
			if (!isDigits(token))
				throw std::runtime_error("Invalid number");
			errno = 0;
			char* end;
			long n = std::strtol(token.c_str(), &end, 10);
			if (errno == ERANGE)
				throw std::out_of_range("overflow");
			if (*end != '\0')
				throw std::runtime_error("invalid number");
			if (n > std::numeric_limits<int>::max())
				throw std::out_of_range("overflow");
			if (std::find(_vector.begin(), _vector.end(), n) != _vector.end())
				throw std::runtime_error("duplicate found");
			_vector.push_back(static_cast<int>(n));
			_deque.push_back(static_cast<int>(n));
		}
	}
	if (_vector.empty())
		throw std::runtime_error("no input provided");
}

/**
 * @brief Executes sorting and measures performance.
 *
 * Sorts the input data using both vector and deque implementations
 * of the Ford–Johnson algorithm, and prints execution times.
 *
 * The function:
 * - Displays the input ("Before")
 * - Sorts using std::vector and measures time
 * - Sorts using std::deque and measures time
 * - Displays the sorted result ("After")
 * - Optionally validates sorting in debug mode
 *
 * @note Timing is performed using gettimeofday() instead of std::clock
 * because gettimeofday provides higher-resolution wall-clock timing,
 * which is more appropriate for microbenchmarking small intervals.
 *
 * @warning Results are platform-dependent due to system timer precision.
 */
void PmergeMe::sort() {
	const double kMicrosecondsPerSecond = 1000000L;
	std::cout << MAG << "Before: " << RESET;
	printContainer(_vector);

	struct timeval start, end;
	// vector
	gettimeofday(&start, NULL);
	sortVector();
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * kMicrosecondsPerSecond
				   + (end.tv_usec - start.tv_usec);
	// deque
	gettimeofday(&start, NULL);
	sortDeque();
	gettimeofday(&end, NULL);
	double decTime = (end.tv_sec - start.tv_sec) * kMicrosecondsPerSecond
				   + (end.tv_usec - start.tv_usec);
	//std::cout << std::fixed << std::setprecision(3);
	std::cout << MAG << "After:  " << RESET;
	printContainer(_vector);

#ifdef DEBUG
	if (!isSorted(_vector))
		std::cout << RED << "Not sorted!\n" << RESET;
	else
		std::cout << GRN << "Sorted!\n" << RESET;
#endif

	std::cout << "Time to process a range of "
			  << _vector.size() << " elements with std::vector : "
			  << vecTime << " µs" << std::endl;
	std::cout << "Time to process a range of "
			  << _deque.size() << " elements with std::deque  : "
			  << decTime << " µs" << std::endl;
}

/**
 * @brief Generates Jacobsthal-based insertion order.
 *
 * Computes a Jacobsthal sequence and transforms it into an insertion
 * order used by the Ford–Johnson algorithm to reduce comparisons.
 *
 * The Jacobsthal sequence is defined as:
 *     J(n) = J(n-1) + 2 * J(n-2)
 *
 * This sequence is then converted into a 0-based index order because
 * elements in the pend container are stored using 0-based indexing.
 *
 * Each Jacobsthal interval is expanded in reverse order to ensure
 * efficient insertion behavior during binary search.
 *
 * @param n Number of elements to generate an insertion order for.
 *
 * @return Vector of indices representing optimized insertion order.
 *
 * @note The returned order is 0-based to match container indexing.
 */
std::vector<int> PmergeMe::generateJacobsthalOrder(size_t n) {
	std::vector<int> order;
	if (n == 0)
		return order;

	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < static_cast<int>(n)) {
		size_t size = jacob.size();
		jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
	}

	int prev = 0;
	for(size_t i = 0; i < jacob.size(); i++) {
		// adjust for 0 base indexing by subtracting 1
		int curr = std::min(static_cast<int>(n), jacob[i]) - 1;
		for (int k = curr; k >= prev; k--) {
			order.push_back(k);
		}
		prev = std::min(static_cast<int>(n), jacob[i]);
		if (prev >= static_cast<int>(n))
			break;
	}

#ifdef DEBUG
	std::cout << YEL << "[DEBUG] " << "jacobs order: ";
	for (size_t i = 0; i < order.size(); i++)
		std::cout << order[i] + 1 << " ";
	std::cout << RESET << std::endl;
#endif

	return order;
}

/**
 * @brief Sorts the internal vector using Ford–Johnson algorithm.
 */
void PmergeMe::sortVector() {
	fordJohnson(_vector, _vectorPairs);
}

/**
 * @brief Sorts the internal deque using Ford–Johnson algorithm.
 */
void PmergeMe::sortDeque() {
	fordJohnson(_deque, _dequePairs);
}

/**
 * @brief Checks whether a string contains only digit characters.
 *
 * Validates that the input string is composed exclusively of numeric
 * characters before conversion.
 *
 * @param str Input string to validate.
 * @return true if the string contains only digits, false otherwise.
 */
bool PmergeMe::isDigits(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

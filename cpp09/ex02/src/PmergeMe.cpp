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

namespace {
	bool isDigits(const std::string& str) {
		for (size_t i = 0; i < str.size(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(str[i])))
				return false;
		}
		return true;
	}
}

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_vectorPairs = other._vectorPairs;
		_deque = other._deque;
		_dequePairs = other._dequePairs;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
}

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
			  << _deque.size() << " elements with std::deque :  "
			  << decTime << " µs" << std::endl;
}

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

void PmergeMe::sortVector() {
	fordJohnson(_vector, _vectorPairs);
}

void PmergeMe::sortDeque() {
	fordJohnson(_deque, _dequePairs);
}

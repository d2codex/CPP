#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>

// colors
#define RED		"\033[31m"
#define GRN		"\033[32m"
#define YEL		"\033[33m"
#define BLU		"\033[34m"
#define MAG		"\033[35m"
#define CYN		"\033[36m"
#define RESET	"\033[0m"

/**
 * @brief Implements Ford–Johnson (merge-insertion) sorting algorithm.
 *
 * This class parses integer input and sorts it using the Ford–Johnson
 * strategy on both std::vector and std::deque containers.
 *
 * The algorithm:
 * - Groups elements into pairs (a < b)
 * - Sorts pairs by their larger element
 * - Builds a main chain from b-elements
 * - Inserts a-elements using Jacobsthal-ordered insertion
 *   to reduce the number of comparisons
 *
 * Two parallel implementations are maintained:
 * - std::vector-based version
 * - std::deque-based version
 *
 * @note Assumes valid integer input and no duplicates.
 * @warning Copy operations are disabled to avoid accidental state duplication.
 */
class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();

	void parseInput(int argc, char** argv);
	void sort();

private:
	// OCF
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	// algorithm
	void				sortVector();
	void				sortDeque();
	std::vector<int>	generateJacobsthalOrder(size_t n);
	
	template <typename Container, typename PairContainer>
	void createPairs(const Container& data, PairContainer& pairs);
	
	template <typename PairContainer>
	void mergePairs(const PairContainer& left,
					const PairContainer& right,
					PairContainer& result);

	template <typename PairContainer>
	void sortPairsByLarger(PairContainer& pairs);
	
	template<typename Container, typename PairContainer>
	void fordJohnson(Container& data, PairContainer& pairs);

	// utils
	bool isDigits(const std::string& str);
	template <typename Container>
	bool isSorted(const Container& container) const;
	
	// data
	std::vector<int>					_vector;
	std::vector<std::pair<int, int> >	_vectorPairs;
	std::deque<int>						_deque;
	std::deque<std::pair<int, int> >	_dequePairs;
};

/**
 * @brief Prints all elements of a container to stdout.
 *
 * Iterates through the container using const iterators and prints
 * each element separated by a space.
 *
 * @tparam Container Any iterable container supporting const_iterator.
 */
template <typename Container>
void printContainer(const Container& c) {
	for (typename Container::const_iterator it = c.begin();
		it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Checks if a container is sorted in ascending order.
 *
 * Compares each adjacent pair of elements to verify non-decreasing order.
 *
 * @tparam Container Any container supporting const_iterator.
 *
 * @param container Container to check.
 *
 * @return true if sorted in ascending order or size < 2, false otherwise.
 *
 * @note Runs in O(n) time.
 */
template <typename Container>
bool PmergeMe::isSorted(const Container& container) const {
	if (container.size() < 2)
		return true;

	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator next = it;
	++next;

	while (next != container.end())
	{
		if (*it > *next)
			return false;
		++it;
		++next;
	}
	return true;
}

/**
 * @brief Splits input data into sorted pairs.
 *
 * Iterates through the container two elements at a time, forming pairs.
 * Each pair is ordered so that first <= second.
 *
 * @tparam Container Input container type.
 * @tparam PairContainer Container holding pairs of integers.
 *
 * @param data Input container of integers.
 * @param pairs Output container storing ordered pairs (a <= b).
 */
template <typename Container, typename PairContainer>
void PmergeMe::createPairs(const Container& data, PairContainer& pairs) {
	pairs.clear();

	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		int a = data[i];
		int b = data[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	
#ifdef DEBUG
	for (size_t i = 0; i < pairs.size(); ++i)
		std::cout << YEL << "[DEBUG] " << RESET
				  << "(" << pairs[i].first
				  << ", " << pairs[i].second << ")\n";
#endif	
}

/**
 * @brief Merges two sorted pair containers.
 *
 * Merges two containers of pairs ordered by their `.second` value
 * into a single sorted result container.
 *
 * Sorting is stable with respect to the `.second` element.
 *
 * @tparam PairContainer Container of std::pair<int,int>.
 *
 * @param left First sorted container.
 * @param right Second sorted container.
 * @param result Output merged and sorted container.
 */
template <typename PairContainer>
void PmergeMe::mergePairs(const PairContainer& left,
				const PairContainer& right,
				PairContainer& result) {
	result.clear();
	size_t i = 0;
	size_t j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].second <= right[j].second)
			result.push_back(left[i++]);
		else
			result.push_back(right[j++]);
	}
	while (i < left.size())
		result.push_back(left[i++]);
	while (j < right.size())
		result.push_back(right[j++]);
}

/**
 * @brief Recursively sorts pairs by their larger element.
 *
 * Implements a merge sort on a container of pairs, using the `.second`
 * value (larger element of each pair) as the sorting key.
 *
 * The container is split into two halves, each sorted recursively,
 * then merged back using mergePairs().
 *
 * @tparam PairContainer Container of std::pair<int,int>.
 *
 * @param pairs Container of pairs to be sorted in-place by `.second`.
 *
 * @note This is part of the preprocessing step of the Ford–Johnson
 * algorithm before building the main and pend sequences.
 *
 * @complexity O(n log n)
 */
template <typename PairContainer>
void PmergeMe::sortPairsByLarger(PairContainer& pairs) {
	if (pairs.size() <= 1)
		return;
	size_t mid = pairs.size() / 2;
	PairContainer left(pairs.begin(), pairs.begin() + mid);
	PairContainer right(pairs.begin() + mid, pairs.end());

	sortPairsByLarger(left);
	sortPairsByLarger(right);
	mergePairs(left, right, pairs);
}

/**
 * @brief Ford–Johnson merge-insertion sort.
 *
 * Builds pairs (a < b), sorts by b, then inserts a-elements into the
 * main chain using a Jacobsthal order to reduce comparisons.
 *
 * Each a[i] is searched only up to its paired b[i]. Because insertions
 * shift positions, `inserted` is used to correct indices.
 *
 * bound = main.begin() + idx + inserted + 1;
 * (+1 because lower_bound uses a half-open range [first, last))
 *
 * @note Assumes no duplicate values (required so each a[i] maps
 * uniquely to a b[i] and binary insertion bounds remain valid).
 */
template<typename Container, typename PairContainer>
void PmergeMe::fordJohnson(Container& data, PairContainer& pairs) {
	if (data.size() <= 1)
		return;
	bool hasOddBall = (data.size() % 2 != 0);
	int oddBall = hasOddBall ? data.back() : -1;

#ifdef DEBUG
	std::cout << YEL << "[DEBUG] " << RESET << "oddBall: ";
	if (oddBall == -1)
		std::cout << MAG << "none\n" << RESET;
	else
		std::cout << MAG << oddBall << RESET << std::endl;
#endif

	createPairs(data, pairs);
	sortPairsByLarger(pairs);

#ifdef DEBUG
	for (size_t i = 0; i < pairs.size(); ++i)
		std::cout << YEL << "[DEBUG] " << RESET
				  << "sort pairs"
				  << YEL << "[" << i + 1 << "]" << RESET
				  << " ("
				  << CYN << pairs[i].first << RESET
				  << ", "
				  << BLU << pairs[i].second << RESET
				  << ")\n";
#endif	

	Container main;
	Container pend;
	
	for (size_t  i = 0; i < pairs.size(); i++) {
		pend.push_back(pairs[i].first);
		main.push_back(pairs[i].second);
	}

#ifdef DEBUG
	std::cout << YEL << "[DEBUG] " << RESET
			  << BLU << "main: ";
	for (size_t i = 0; i < main.size(); i++) {
		std::cout << main[i] << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << YEL << "[DEBUG] " << RESET
			  << CYN << "pend: ";
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << pend[i] << " ";
	}
	std::cout << RESET << std::endl;
#endif

	std::vector<int> order = generateJacobsthalOrder(pend.size());
	int inserted = 0;
	for (size_t i = 0; i < order.size(); i++) {
		int idx = order[i];
		typename Container::iterator bound;
			if (idx == 0)
				bound = main.begin() + 1;
			else
				// idx = original position
				// inserted = shift caused by previous insertions
				// shift the upper bound one past the last element we want to include
				bound = main.begin() + idx + inserted + 1;
		typename Container::iterator pos =
			std::lower_bound(main.begin(), bound,  pend[idx]);
		main.insert(pos, pend[idx]);
		inserted++;
	}
	//insertOddBall
	if (hasOddBall) {
		typename Container::iterator pos =
			std::lower_bound(main.begin(), main.end(), oddBall);
		main.insert(pos, oddBall);
	}
	data = main;
}

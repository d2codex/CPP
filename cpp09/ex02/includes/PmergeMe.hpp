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
	template <typename Container>
	bool isSorted(const Container& container) const;
	
	// data
	std::vector<int>					_vector;
	std::vector<std::pair<int, int> >	_vectorPairs;
	std::deque<int>						_deque;
	std::deque<std::pair<int, int> >	_dequePairs;
};

template <typename Container>
void printContainer(const Container& c) {
	for (typename Container::const_iterator it = c.begin();
		it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

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

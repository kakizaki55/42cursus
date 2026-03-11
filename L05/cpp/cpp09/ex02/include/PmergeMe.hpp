#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int>  _deq;
	std::vector<int> _original; // unsorted copy for "Before:" line
	int _displayLimit;

	double _vecTime;
	double _deqTime;

	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	static void fordJohnsonVec(std::vector<int>& arr);
	// static void fordJohnsonDeq(std::deque<int>& arr);

public:
	PmergeMe();
	~PmergeMe();

	void parseArgs(int argc, char **argv);
	void sort();

	void printBefore() const;
	void printAfter()  const;
	double timeVec()   const;
	double timeDeq()   const;
	std::size_t size() const;
};


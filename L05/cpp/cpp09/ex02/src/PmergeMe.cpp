#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <ctime>
#include <climits>

/* ══════════════════  Shared Jacobsthal helper  ═════════════════════ */
// Returns the boundary sequence: 0, 1, 3, 5, 11, 21, 43, …
// (each element = prev + 2 * prev-prev)
// Stops once the last value >= n.

static std::vector<int> makeJacobsthal(int n)
{
	std::vector<int> sequence;

	sequence.push_back(0);
	sequence.push_back(1);

	while (sequence.back() < n)
	{
		int last		= sequence[sequence.size() - 1];
		int secondLast	= sequence[sequence.size() - 2];
		sequence.push_back(last + 2 * secondLast);
	}
	return sequence;
}

/* ═══════════════════  V E C T O R   version  ═══════════════════════ */

/*
 * Ford-Johnson (merge-insertion) sort — vector
 *
 * 1. Pair adjacent elements; within each pair keep (larger, smaller).
 * 2. Recursively Ford-Johnson-sort the sequence of "larger" elements.
 * 3. stable_sort pairs by first element to realign with the sorted order.
 * 4. Build main chain  [ b₀, a₀, a₁, …, aₖ₋₁ ].
 * 5. Insert remaining pending elements in Jacobsthal insertion order,
 *    bounding each binary search to [0, pos(aᵢ)] since bᵢ ≤ aᵢ.
 * 6. Handle odd straggler with an unbounded binary search.
 */
void PmergeMe::fordJohnsonVec(std::vector<int>& arr)
{
	int n = (int)arr.size();
	if (n <= 1) return;

	bool odd = (n % 2 != 0);
	int straggler = odd ? arr[n - 1] : 0;
	int k = n / 2;

	std::vector<std::pair<int, int> > pairs(k);
	for (int i = 0; i < k; i++) {
		int a = arr[2 * i], b = arr[2 * i + 1];
		if (a < b) std::swap(a, b);
		pairs[i] = std::make_pair(a, b);
	}

	std::vector<int> larger(k);
	for (int i = 0; i < k; i++) larger[i] = pairs[i].first;
	fordJohnsonVec(larger); // recursive call

	std::stable_sort(pairs.begin(), pairs.end()); // sort pairs to match sorted larger

	// Build main chain: [ b₀ , a₀ , a₁ , … , aₖ₋₁ ]
	std::vector<int> chain;
	chain.reserve(n);
	chain.push_back(pairs[0].second);
	for (int i = 0; i < k; i++) chain.push_back(larger[i]);

	// aPos[i] = current index of aᵢ in chain
	std::vector<int> aPos(k);
	for (int i = 0; i < k; i++) aPos[i] = i + 1;

	std::vector<bool> done(k, false);
	done[0] = true; // b₀ already inserted

	std::vector<int> jac = makeJacobsthal(k);

	// For each Jacobsthal group, insert its pend elements from high idx to low
	for (int gi = 1; gi < (int)jac.size() - 1; gi++) {
		int lo_idx = jac[gi];
		int hi_idx = std::min(jac[gi + 1] - 1, k - 1);
		for (int idx = hi_idx; idx >= lo_idx; idx--) {
			if (done[idx]) continue;
			done[idx] = true;

			int bval     = pairs[idx].second;
			int ins_lo   = 0;
			int ins_hi   = aPos[idx] + 1; // bᵢ ≤ aᵢ → bound search
			while (ins_lo < ins_hi) {
				int mid = ins_lo + (ins_hi - ins_lo) / 2;
				if (chain[mid] < bval) ins_lo = mid + 1;
				else                   ins_hi = mid;
			}
			chain.insert(chain.begin() + ins_lo, bval);
			for (int j = 0; j < k; j++)
				if (aPos[j] >= ins_lo) aPos[j]++;
		}
	}

	if (odd) {
		int ins_lo = 0, ins_hi = (int)chain.size();
		while (ins_lo < ins_hi) {
			int mid = ins_lo + (ins_hi - ins_lo) / 2;
			if (chain[mid] < straggler) ins_lo = mid + 1;
			else                        ins_hi = mid;
		}
		chain.insert(chain.begin() + ins_lo, straggler);
	}

	arr = chain;
}

/* ═══════════════════  D E Q U E   version  ════════════════════════ */

// static std::deque<int> makeJacobsthalDeq(int n)
// {
// 	std::deque<int> j;
// 	j.push_back(0);
// 	j.push_back(1);
// 	while (j.back() < n) {
// 		int sz = (int)j.size();
// 		j.push_back(j[sz - 1] + 2 * j[sz - 2]);
// 	}
// 	return j;
// }

// void PmergeMe::fordJohnsonDeq(std::deque<int>& arr)
// {
// 	int n = (int)arr.size();
// 	if (n <= 1) return;

// 	bool odd = (n % 2 != 0);
// 	int straggler = odd ? arr[n - 1] : 0;
// 	int k = n / 2;

// 	std::deque<std::pair<int, int> > pairs(k);
// 	for (int i = 0; i < k; i++) {
// 		int a = arr[2 * i], b = arr[2 * i + 1];
// 		if (a < b) std::swap(a, b);
// 		pairs[i] = std::make_pair(a, b);
// 	}

// 	std::deque<int> larger(k);
// 	for (int i = 0; i < k; i++) larger[i] = pairs[i].first;
// 	fordJohnsonDeq(larger);

// 	std::stable_sort(pairs.begin(), pairs.end());

// 	std::deque<int> chain;
// 	chain.push_back(pairs[0].second);
// 	for (int i = 0; i < k; i++) chain.push_back(larger[i]);

// 	std::deque<int> aPos(k);
// 	for (int i = 0; i < k; i++) aPos[i] = i + 1;

// 	std::deque<bool> done(k, false);
// 	done[0] = true;

// 	std::deque<int> jac = makeJacobsthalDeq(k);

// 	for (int gi = 1; gi < (int)jac.size() - 1; gi++) {
// 		int lo_idx = jac[gi];
// 		int hi_idx = std::min(jac[gi + 1] - 1, k - 1);
// 		for (int idx = hi_idx; idx >= lo_idx; idx--) {
// 			if (done[idx]) continue;
// 			done[idx] = true;

// 			int bval   = pairs[idx].second;
// 			int ins_lo = 0;
// 			int ins_hi = aPos[idx] + 1;
// 			while (ins_lo < ins_hi) {
// 				int mid = ins_lo + (ins_hi - ins_lo) / 2;
// 				if (chain[mid] < bval) ins_lo = mid + 1;
// 				else                   ins_hi = mid;
// 			}
// 			chain.insert(chain.begin() + ins_lo, bval);
// 			for (int j = 0; j < k; j++)
// 				if (aPos[j] >= ins_lo) aPos[j]++;
// 		}
// 	}

// 	if (odd) {
// 		int ins_lo = 0, ins_hi = (int)chain.size();
// 		while (ins_lo < ins_hi) {
// 			int mid = ins_lo + (ins_hi - ins_lo) / 2;
// 			if (chain[mid] < straggler) ins_lo = mid + 1;
// 			else                        ins_hi = mid;
// 		}
// 		chain.insert(chain.begin() + ins_lo, straggler);
// 	}

// 	arr = chain;
// }

/* ══════════════════════  P m e r g e M e  ══════════════════════════ */

PmergeMe::PmergeMe() : _displayLimit(10), _vecTime(0.0), _deqTime(0.0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {
		this->_vec = other._vec;
		this->_deq = other._deq;
		this->_original = other._original;
		this->_vecTime = other._vecTime;
		this->_deqTime = other._deqTime;
		this->_displayLimit = other._displayLimit;
	}
	return *this;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error");
		for (std::size_t j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[j])))
				throw std::runtime_error("Error");
		}
		std::istringstream iss(token);
		long val;
		iss >> val;
		if (val <= 0 || val > INT_MAX)
			throw std::runtime_error("Error: Number out of range");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
		_original.push_back(static_cast<int>(val));
	}
	if (_vec.empty())
		throw std::runtime_error("Error: No valid numbers provided");
}

void PmergeMe::sort()
{
	// Time vector sort
	{
		std::clock_t start = std::clock();
		fordJohnsonVec(_vec);
		std::clock_t end = std::clock();
		_vecTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	}
	// // Time deque sort
	// {
	// 	std::clock_t start = std::clock();
	// 	fordJohnsonDeq(_deq);
	// 	std::clock_t end = std::clock();
	// 	_deqTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	// }
}

void PmergeMe::printBefore() const	
{
	std::cout << "Before: ";
	if (_displayLimit < (int)_original.size())
	{
		for (std::size_t i = 0; i < (std::size_t)_displayLimit; i++)
		{
			if (i) std::cout << ' ';
			std::cout << _original[i];
		}
		std::cout << " [...]";
	}
	else
	{
		for (std::size_t i = 0; i < _original.size(); i++)
		{
			if (i) std::cout << ' ';
			std::cout << _original[i];
		}
	}
	std::cout << '\n';
}

void PmergeMe::printAfter() const
{
	std::cout << "After:  ";
	if (_displayLimit < (int)_vec.size())
	{
		for (std::size_t i = 0; i < (std::size_t)_displayLimit; i++)
		{
			if (i) std::cout << ' ';
			std::cout << _vec[i];
		}
		std::cout << " [...]";
	}
	else
	{
		for (std::size_t i = 0; i < _vec.size(); i++)
		{
			if (i) std::cout << ' ';
			std::cout << _vec[i];
		}
	}
	std::cout << '\n';
}

double PmergeMe::timeVec() const
{
	return _vecTime;
}
double PmergeMe::timeDeq() const  
{
	 return _deqTime; 
}
std::size_t PmergeMe::size() const { return _vec.size(); }

#include "PmergeMe.hpp"
#include <algorithm>

static std::vector<int> makeJacobsthal(int n)
{
	// Produces: 1, 3, 5, 11, 21, 43, ...
	// These are the group boundary indices for b-element insertion.
	// Starting with [1, 3] avoids the duplicate 1 from [0, 1].
	std::vector<int> jac;
	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < n)
	{
		int last		= jac[jac.size() - 1];
		int secondLast	= jac[jac.size() - 2];
		jac.push_back(last + 2 * secondLast);
	}
	return jac;
}

static std::vector<int> buildInitialChain(const std::vector<int>& largerElements, const std::vector<std::pair<int, int> >& pairs, int numPairs)
{
	std::vector<int> chain;
	chain.reserve(numPairs + 1);

	chain.push_back(pairs[0].second);
	for (int i = 0; i < numPairs; i++)
		chain.push_back(largerElements[i]);

	return chain;
}

static std::vector<std::pair<int, int> > pairUpElements(const std::vector<int>& arr, int numPairs)
{
	std::vector<std::pair<int, int> > pairs(numPairs);
	for (int i = 0; i < numPairs; i++)
		pairs[i] = std::make_pair(arr[2 * i], arr[2 * i + 1]);
	return pairs;
}

// Orient a single pair so .first (larger) >= .second (smaller)
static void orientPair(std::pair<int,int>& p)
{
	++g_comp;
	if (p.first < p.second)
		std::swap(p.first, p.second);
}

// Reorder pairs so pairs[i].first == sortedLargers[i].
// This is pure bookkeeping — no algorithmic comparisons, so no g_comp.
static void reorderPairsByLarger(std::vector<std::pair<int,int> >& pairs,
                                  const std::vector<int>& sortedLargers,
                                  int numPairs)
{
	std::vector<bool>             used(numPairs, false);
	std::vector<std::pair<int,int> > ordered(numPairs);

	for (int i = 0; i < numPairs; i++)
	{
		for (int j = 0; j < numPairs; j++)
		{
			if (!used[j] && pairs[j].first == sortedLargers[i])
			{
				ordered[i] = pairs[j];
				used[j] = true;
				break;
			}
		}
	}
	pairs = ordered;
}


void PmergeMe::fordJohnsonVec(std::vector<int>& arr)
{
	int size = (int)arr.size();
	if (size <= 1)
		return;

	// If odd number of elements, save the last one for later
	bool hasStraggler = (size % 2 != 0);
	int  straggler    = hasStraggler ? arr[size - 1] : 0;
	int  numPairs     = size / 2;




	std::vector<std::pair<int, int> > pairs = pairUpElements(arr, numPairs);

	// Step 1: orient each pair so .first >= .second  (n/2 comparisons)
	for (int i = 0; i < numPairs; i++)
		orientPair(pairs[i]);

	// Step 2: recursively sort the larger elements using Ford-Johnson
	std::vector<int> largerElements(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElements[i] = pairs[i].first;

	fordJohnsonVec(largerElements);

	// Step 3: reorder pairs to match the sorted largerElements (no g_comp)
	reorderPairsByLarger(pairs, largerElements, numPairs);

	std::vector<int> chain = buildInitialChain(largerElements, pairs, numPairs);

	
	std::vector<int> largerElementPositions(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElementPositions[i] = i + 1;

	// smallest is already in the chain, mark it done
	std::vector<bool> inserted(numPairs, false);
	inserted[0] = true;

	std::vector<int> jacobsthal = makeJacobsthal(numPairs);

	// jac = [1, 3, 5, 11, 21, ...]
	// Group k covers pair indices [jac[k], jac[k+1]-1], inserted high-to-low.
	for (int groupIndex = 0; groupIndex + 1 < (int)jacobsthal.size(); groupIndex++)
	{
		int groupStart = jacobsthal[groupIndex];
		int groupEnd   = std::min(jacobsthal[groupIndex + 1] - 1, numPairs - 1);

		// Insert from high to low within each group to tighten search bounds
		for (int pairIndex = groupEnd; pairIndex >= groupStart; pairIndex--)
		{
			if (inserted[pairIndex])
				continue;
			inserted[pairIndex] = true;

			int smallerValue    = pairs[pairIndex].second;
			int searchRangeLow  = 0;
			// b_k < a_k is guaranteed by pairing, so search only up to (not including) pos(a_k)
			int searchRangeHigh = largerElementPositions[pairIndex];

			while (searchRangeLow < searchRangeHigh)
			{
				int mid = searchRangeLow + (searchRangeHigh - searchRangeLow) / 2;
				++g_comp; // binary search comparison
				if (chain[mid] < smallerValue)
					searchRangeLow = mid + 1;
				else
					searchRangeHigh = mid;
			}

			chain.insert(chain.begin() + searchRangeLow, smallerValue);

			for (int j = 0; j < numPairs; j++)
				if (largerElementPositions[j] >= searchRangeLow)
					largerElementPositions[j]++;
		}
	}

	if (hasStraggler)
	{
		int searchRangeLow  = 0;
		int searchRangeHigh = (int)chain.size();

		while (searchRangeLow < searchRangeHigh)
		{
			int mid = searchRangeLow + (searchRangeHigh - searchRangeLow) / 2;
			++g_comp; // stragerler binary search comparison
			if (chain[mid] < straggler)
				searchRangeLow = mid + 1;
			else
				searchRangeHigh = mid;
		}
		chain.insert(chain.begin() + searchRangeLow, straggler);
	}

	arr = chain;
}

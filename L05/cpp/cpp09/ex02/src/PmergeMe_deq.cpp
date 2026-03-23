#include "PmergeMe.hpp"
#include <algorithm>

static std::deque<int> makeJacobsthal(int n)
{
	// Produces: 1, 3, 5, 11, 21, 43, ...
	std::deque<int> jac;
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

static std::deque<int> buildInitialChain(const std::deque<int>& largerElements, const std::deque<std::pair<int, int> >& pairs, int numPairs)
{
	std::deque<int> chain;

	chain.push_back(pairs[0].second);
	for (int i = 0; i < numPairs; i++)
		chain.push_back(largerElements[i]);

	return chain;
}

static std::deque<std::pair<int, int> > pairUpElements(const std::deque<int>& arr, int numPairs)
{
	std::deque<std::pair<int, int> > pairs(numPairs);
	for (int i = 0; i < numPairs; i++)
		pairs[i] = std::make_pair(arr[2 * i], arr[2 * i + 1]);
	return pairs;
}

static void orientPair(std::pair<int,int>& p)
{
	if (p.first < p.second)
		std::swap(p.first, p.second);
}

static void reorderPairsByLarger(std::deque<std::pair<int,int> >& pairs,
                                  const std::deque<int>& sortedLargers,
                                  int numPairs)
{
	std::deque<bool>             used(numPairs, false);
	std::deque<std::pair<int,int> > ordered(numPairs);

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


void PmergeMe::fordJohnsonDeq(std::deque<int>& arr)
{
	int size = (int)arr.size();
	if (size <= 1)
		return;

	bool hasStraggler = (size % 2 != 0);
	int  straggler    = hasStraggler ? arr[size - 1] : 0;
	int  numPairs     = size / 2;

	std::deque<std::pair<int, int> > pairs = pairUpElements(arr, numPairs);

	for (int i = 0; i < numPairs; i++)
		orientPair(pairs[i]);

	std::deque<int> largerElements(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElements[i] = pairs[i].first;

	fordJohnsonDeq(largerElements);

	reorderPairsByLarger(pairs, largerElements, numPairs);

	std::deque<int> chain = buildInitialChain(largerElements, pairs, numPairs);
	
	std::deque<int> largerElementPositions(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElementPositions[i] = i + 1;

	// smallest is already in the chain, mark it done
	std::deque<bool> inserted(numPairs, false);
	inserted[0] = true;

	std::deque<int> jacobsthal = makeJacobsthal(numPairs);

	for (int groupIndex = 0; groupIndex + 1 < (int)jacobsthal.size(); groupIndex++)
	{
		int groupStart = jacobsthal[groupIndex];
		int groupEnd   = std::min(jacobsthal[groupIndex + 1] - 1, numPairs - 1);

		for (int pairIndex = groupEnd; pairIndex >= groupStart; pairIndex--)
		{
			if (inserted[pairIndex])
				continue;
			inserted[pairIndex] = true;

			int smallerValue    = pairs[pairIndex].second;
			int searchRangeLow  = 0;
			int searchRangeHigh = largerElementPositions[pairIndex];

			while (searchRangeLow < searchRangeHigh)
			{
				int mid = searchRangeLow + (searchRangeHigh - searchRangeLow) / 2;
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
			if (chain[mid] < straggler)
				searchRangeLow = mid + 1;
			else
				searchRangeHigh = mid;
		}
		chain.insert(chain.begin() + searchRangeLow, straggler);
	}

	arr = chain;
}

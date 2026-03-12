#include "PmergeMe.hpp"
#include <algorithm>

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
	{
		int left  = arr[2 * i];
		int right = arr[2 * i + 1];
		if (left < right)
			std::swap(left, right);
		pairs[i] = std::make_pair(left, right);
	}
	return pairs;
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

	std::vector<int> largerElements(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElements[i] = pairs[i].first;

	fordJohnsonVec(largerElements);

	std::stable_sort(pairs.begin(), pairs.end());

	std::vector<int> chain = buildInitialChain(largerElements, pairs, numPairs);

	std::vector<int> largerElementPositions(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElementPositions[i] = i + 1;

	// smallest is already in the chain, mark it done
	std::vector<bool> inserted(numPairs, false);
	inserted[0] = true;

	std::vector<int> jacobsthal = makeJacobsthal(numPairs);

	for (int groupIndex = 1; groupIndex < (int)jacobsthal.size() - 1; groupIndex++)
	{
		int groupStart = jacobsthal[groupIndex];
		int groupEnd   = std::min(jacobsthal[groupIndex + 1] - 1, numPairs - 1);

		// Insert from high to low within each group to tighten search bounds
		for (int pairIndex = groupEnd; pairIndex >= groupStart; pairIndex--)
		{
			if (inserted[pairIndex])
				continue;
			inserted[pairIndex] = true;

			int smallerValue   = pairs[pairIndex].second;
			int searchRangeLow = 0;
			int searchRangeHigh = largerElementPositions[pairIndex] + 1;

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

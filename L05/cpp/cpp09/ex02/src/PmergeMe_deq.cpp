#include "PmergeMe.hpp"
#include <algorithm>

static std::deque<int> makeJacobsthal(int n)
{
	std::deque<int> sequence;

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

static std::deque<int> buildInitialChain(const std::deque<int>& largerElements, const std::deque<std::pair<int, int> >& pairs, int numPairs)
{
	std::deque<int> chain(numPairs + 1);
	// chain.reserve(numPairs + 1);

	chain.push_back(pairs[0].second);
	for (int i = 0; i < numPairs; i++)
		chain.push_back(largerElements[i]);

	return chain;
}

static std::deque<std::pair<int, int> > pairUpElements(const std::deque<int>& arr, int numPairs)
{
	std::deque<std::pair<int, int> > pairs(numPairs);
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

void PmergeMe::fordJohnsonDeq(std::deque<int>& arr)
{
	int size = (int)arr.size();
	if (size <= 1)
		return;

	// If odd number of elements, save the last one for later
	bool hasStraggler = (size % 2 != 0);
	int  straggler    = hasStraggler ? arr[size - 1] : 0;
	int  numPairs     = size / 2;

	// Step 1: pair up elements, ensure larger is first in each pair
	std::deque<std::pair<int, int> > pairs = pairUpElements(arr, numPairs);

	// Step 2: collect the larger elements and sort them recursively
	std::deque<int> largerElements(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElements[i] = pairs[i].first;

	fordJohnsonDeq(largerElements);

	// Step 3: re-align pairs to match the sorted larger elements
	std::stable_sort(pairs.begin(), pairs.end());

	// take the smaller element of the left, then all the largest element to the right
	std::deque<int> chain = buildInitialChain(largerElements, pairs, numPairs);

	// Step 5: track the positions of the larger elements in the chain
	std::deque<int> largerElementPositions(numPairs);
	for (int i = 0; i < numPairs; i++)
		largerElementPositions[i] = i + 1;

	// b0 is already in the chain, mark it done
	std::deque<bool> inserted(numPairs, false);
	inserted[0] = true;

	// Step 6: use Jacobsthal sequence to determine insertion order of smaller elements
	std::deque<int> jacobsthal = makeJacobsthal(numPairs);

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

			// Binary search for the correct insertion point
			while (searchRangeLow < searchRangeHigh)
			{
				int mid = searchRangeLow + (searchRangeHigh - searchRangeLow) / 2;
				if (chain[mid] < smallerValue)
					searchRangeLow = mid + 1;
				else
					searchRangeHigh = mid;
			}

			chain.insert(chain.begin() + searchRangeLow, smallerValue);

			// Shift all tracked positions that are at or past the insertion point
			for (int j = 0; j < numPairs; j++)
				if (largerElementPositions[j] >= searchRangeLow)
					largerElementPositions[j]++;
		}
	}

	// Step 7: if there was an odd element, binary search insert it at the end
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

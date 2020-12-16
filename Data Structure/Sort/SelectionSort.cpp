#include "SelectionSort.h"

void SelectionSort::__swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort::sort(std::vector<int>& nums)
{
	int length = nums.size();

	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (nums[i] > nums[j])
			{
				__swap(nums[i], nums[j]);
			}
		}
	}
}

#pragma once
#include "BubbleSort.h"


	// ����������
void BubbleSort::__swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

	// ð������
void BubbleSort::sort(std::vector<int>& nums)
{
	bool mark = false;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		mark = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				mark = true;
				__swap(nums[j], nums[j + 1]);
			}
		}
		if (!mark)
			break;
	}
}
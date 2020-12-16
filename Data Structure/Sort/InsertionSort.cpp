#pragma once
#include "InsertionSort.h"


// ����������
void InsertionSort::__swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ��������
void InsertionSort::sort(std::vector<int>& nums)
{
	int length = nums.size();
	if (length <= 1)
		return;
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (nums[j] < nums[j - 1])
			{
				__swap(nums[j], nums[j - 1]);
			}
			else
				break;
		}
	}
}


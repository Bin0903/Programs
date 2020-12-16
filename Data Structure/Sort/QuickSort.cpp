#include "QuickSort.h"

void QuickSort::__swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort::sort(std::vector<int>& nums)
{
	int left = 0;
	int right = nums.size()-1;

	sort(nums, left, right);
}

void QuickSort::sort(std::vector<int>& nums, int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int key = nums[i];
	
	while (i < j)
	{
		while (i < j && nums[j] >= key)
		{
			j--;
		}
		nums[i] = nums[j];
		while (i < j && nums[i] <= key)
		{
			i++;
		}
		nums[j] = nums[i];
	}

	nums[i] = key;

	sort(nums, left, i-1);
	sort(nums, i + 1, right);
}


//void QuickSort::sort(std::vector<int>& nums, int left, int right)
//{
//	if (left >= right)
//		return;
//	int i = left;
//	int j = right;
//	int key = nums[left];
//
//	while (true)
//	{
//		while (nums[++i] <= key)
//		{
//			if (i == right)
//				break;
//		}
//		while (nums[j--] >= key)
//		{
//			if (j == left)
//				break;
//		}
//		if (i >= j)
//			break;
//		__swap(nums[j], nums[i]);
//
//	}
//
//	nums[left] = nums[j];
//	nums[j] = key;
//
//	sort(nums, left, j - 1);
//	sort(nums, j + 1, right);
//}

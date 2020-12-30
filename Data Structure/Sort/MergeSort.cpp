#include "MergeSort.h"

void MergeSort::merge(std::vector<int>& nums, int left, int mid, int right)
{
	int length = right - left+2;
	int* temp = new int[length];

	memset(temp, 0, sizeof(temp));

	int i = left, j = mid+1;

	int p = 0;
	while (i < mid+1 && j < right+1)
	{
		if (nums[i] <= nums[j])
			temp[p++] = nums[i++];
		else
			temp[p++] = nums[j++];
	}

	while (i <= mid)
	{
		temp[p++] = nums[i++];
	}
	while(j<=right)
	{
		temp[p++] = nums[j++];
	}

	p = 0;
	while (left <= right)
	{
		nums[left++] = temp[p++];
	}

	delete[] temp;
}

void MergeSort::sort(std::vector<int>& nums)
{
	sort(nums, 0, nums.size()-1);
}

void MergeSort::sort(std::vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		sort(nums, left, mid);
		sort(nums, mid+1, right);

		merge(nums, left, mid, right);
	}
}
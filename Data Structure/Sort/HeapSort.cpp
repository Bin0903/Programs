#include "HeapSort.h"

void HeapSort::__swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void HeapSort::bulidMaxHeap(std::vector<int>& nums)
{
	int length = nums.size();
	for (int i = (length - 2) / 2; i >= 0; i--)
	{
		maxHeapify(nums, i, length);
	}
}

void HeapSort::maxHeapify(std::vector<int>& nums, int root, int length)
{	
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	if (left > (length-1))
		return;
	
	if (right > (length-1))
	{
		if (nums[left] > nums[root])
			__swap(nums[left], nums[root]);
		return;
	}
	
	int larger = nums[left] > nums[right] ? left : right;

	if (nums[larger] > nums[root])
	{
		__swap(nums[larger], nums[root]);
		maxHeapify(nums, larger, length);
	}
	return;
}

void HeapSort::sort(std::vector<int>& nums)
{
	int length = nums.size();

	int root_size = (length - 2) / 2;

	// 调整成大根堆
	bulidMaxHeap(nums);

	while (length > 1)
	{
		length--;
		__swap(nums[0], nums[length]);
		maxHeapify(nums, 0, length);
	}
	
}
#pragma once
#include "vector"

class HeapSort
{
private:
	void __swap(int& a, int& b);
public:
	void bulidMaxHeap(std::vector<int>& nums);
	void maxHeapify(std::vector<int>& nums, int root, int length);
	void sort(std::vector<int>& nums);
};


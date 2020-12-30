#pragma once
#include "vector"

class MergeSort
{
public:
	void sort(std::vector<int>& nums);

	void sort(std::vector<int>& nums, int left, int right);

	void merge(std::vector<int>& nums, int left, int mid, int right);
};


#pragma once

#include "iostream"
#include "vector"

class QuickSort
{
private:
	void __swap(int& a, int& b);
public:
	void sort(std::vector<int>& nums, int left, int right);
	void sort(std::vector<int>& nums);
};


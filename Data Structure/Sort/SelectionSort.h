#pragma once
#include "iostream"
#include "vector"

class SelectionSort
{
private:
	void __swap(int& a, int& b);
public:
	void sort(std::vector<int>& nums);
};


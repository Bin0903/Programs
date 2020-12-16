#pragma once
#include "iostream"
#include "vector"

class InsertionSort
{
private:
	// 交换两个数
	void __swap(int& a, int& b);
public:
	// 插入排序
	void sort(std::vector<int>& nums);
};


#pragma once
#include "iostream"
#include "vector"

class BubbleSort
{
private:
	// 交换两个数
	void __swap(int& a, int& b);
public:
	// 冒泡排序
	void sort(std::vector<int>& nums);
};


#pragma once
#include "iostream"
#include "vector"

class BubbleSort
{
private:
	// ����������
	void __swap(int& a, int& b);
public:
	// ð������
	void sort(std::vector<int>& nums);
};


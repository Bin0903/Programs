#pragma once
#include "iostream"
#include "vector"

class InsertionSort
{
private:
	// ����������
	void __exchange(int& a, int& b);
public:
	// ��������
	void sort(std::vector<int>& nums);
};


#pragma once
#include "iostream"
#include "vector"

class CountingSort
{
public:
	void sort(std::vector<int>& nums)
	{
		int length = nums.size();
	
		// 获得数据中的最大值和最小值
		int max = INT_MIN, min = INT_MAX;

		for (int i = 0; i < length; i++)
		{
			if (max < nums[i])
				max = nums[i];
			if (min > nums[i])
				min = nums[i];
		}

		// 计算cnt数组的范围
		int range = max - min + 1;

		// 动态内存分配
		int *cnt = new int[range];
		// 将cnt中的内容初始化为0
		memset(cnt, 0, range * sizeof(int));
		
		// 计算每个数的频次
		for (int i = 0; i < length; i++)
			cnt[nums[i]- min] += 1;
		// 转换为累计频次
		for (int i = 0; i < range-1; i++)
			cnt[i + 1] += cnt[i];

		// Debug
		//for (int i = 0; i < length; i++)
		//	std::cout << cnt[nums[i] - min] << std::endl;

		// 开辟与原始数据相同大小的空间，用于暂存排好的数据
		int *ranked = new int[length];
		memset(ranked, 0, length * sizeof(int));

		// 将每个数放到该放的地方
		for (int i = length - 1; i >= 0; i--)
			ranked[--cnt[nums[i] - min]] = nums[i] - min;

		// 用排好的数据覆盖原始数据
		for (int i = 0; i < length; i++)
			nums[i] = ranked[i];

		// 返还申请的内存
		delete[] cnt;
		delete[] ranked;
	}
};


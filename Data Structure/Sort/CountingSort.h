#pragma once
#include "iostream"
#include "vector"

class CountingSort
{
public:
	void sort(std::vector<int>& nums)
	{
		int length = nums.size();
	
		// ��������е����ֵ����Сֵ
		int max = INT_MIN, min = INT_MAX;

		for (int i = 0; i < length; i++)
		{
			if (max < nums[i])
				max = nums[i];
			if (min > nums[i])
				min = nums[i];
		}

		// ����cnt����ķ�Χ
		int range = max - min + 1;

		// ��̬�ڴ����
		int *cnt = new int[range];
		// ��cnt�е����ݳ�ʼ��Ϊ0
		memset(cnt, 0, range * sizeof(int));
		
		// ����ÿ������Ƶ��
		for (int i = 0; i < length; i++)
			cnt[nums[i]- min] += 1;
		// ת��Ϊ�ۼ�Ƶ��
		for (int i = 0; i < range-1; i++)
			cnt[i + 1] += cnt[i];

		// Debug
		//for (int i = 0; i < length; i++)
		//	std::cout << cnt[nums[i] - min] << std::endl;

		// ������ԭʼ������ͬ��С�Ŀռ䣬�����ݴ��źõ�����
		int *ranked = new int[length];
		memset(ranked, 0, length * sizeof(int));

		// ��ÿ�����ŵ��÷ŵĵط�
		for (int i = length - 1; i >= 0; i--)
			ranked[--cnt[nums[i] - min]] = nums[i] - min;

		// ���źõ����ݸ���ԭʼ����
		for (int i = 0; i < length; i++)
			nums[i] = ranked[i];

		// ����������ڴ�
		delete[] cnt;
		delete[] ranked;
	}
};


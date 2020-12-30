#include "iostream"
#include "stdlib.h"
#include "time.h"

#include "BubbleSort.h"
#include "CountingSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

constexpr int N = 10000;

using namespace std;

int main()
{
	//vector<int> nums = vector<int>({9,8,7,6,5,4,3,2,1,0});
	//MergeSort obj = MergeSort();
	//obj.sort(nums, 0, nums.size()-1);
	//for (auto& num : nums)
	//{
	//	cout << num << endl;
	//}
	//return 0;


	// 生成N个乱序的随机数
	vector<int> array;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
	{
		array.push_back(rand()%N);
	}

	// 排序并记录所消耗的时间
	BubbleSort objBubbleSort = BubbleSort();
	CountingSort objCountingSort = CountingSort();
	InsertionSort objInsertionSort = InsertionSort();
	SelectionSort objSelectionSort = SelectionSort();
	QuickSort objQuickSort = QuickSort();
	HeapSort objHeapSort = HeapSort();
	MergeSort objMergeSort = MergeSort();
	

	clock_t beginTime, endTime;
	beginTime = clock();

	// 排序
	/*
	* *********************
	*/
	//objBubbleSort.sort(array);
	//objCountingSort.sort(array);
	//objSelectionSort.sort(array);
	//objQuickSort.sort(array);
	//objHeapSort.sort(array);
	//objInsertionSort.sort(array);
	objMergeSort.sort(array);
	/*
	* *********************
	*/

	endTime = clock();

	cout << "Total time:" << ((double)endTime - beginTime)/CLOCKS_PER_SEC << "s" << endl;

	for (int i = 0; i < N-1; i++)
	{
		cout << array[i] << ",";
	}
	cout << array[N - 1] << endl;
	return 0;
}
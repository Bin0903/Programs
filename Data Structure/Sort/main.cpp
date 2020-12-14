#include "iostream"
#include "BubbleSort.h"
#include "CountingSort.h"

#include "stdlib.h"
#include "time.h"

#define N 10000

using namespace std;

int main()
{
	// ����N������������
	vector<int> array;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
	{
		array.push_back(rand()%N);
	}

	// ���򲢼�¼�����ĵ�ʱ��
	BubbleSort objBubbleSort = BubbleSort();
	CountingSort objCountingSort = CountingSort();

	clock_t beginTime, endTime;
	beginTime = clock();

	// ����
	/*
	* *********************
	*/
	objBubbleSort.sort(array);
	//objCountingSort.sort(array);
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
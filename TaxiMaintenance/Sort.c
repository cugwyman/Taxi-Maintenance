#include "Sort.h"

//交换函数
void Swap(int *a, int i, int j) {
	int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//无中间变量交换函数，利用^=异或
void SwapWithoutTemp(int *a, int i, int j)
{
	if (a[i] != a[j])
	{
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
	}
}

//打印序列函数
void PrintArr(int *a) {
	for (int i = 0; i<LEN; i++) {
		printf("%d  ", a[i]);
	}
}

//BubbleSort冒泡排序，复杂度O(n^2)
//@param flag		优化算法
void BubbleSort(int *a) {
	int flag = 1;
	for (int i = 0; i < LEN && flag; i++) {
		flag = 0;		//若flag经j循环后为0，则序列已有序
		for (int j = 1; j < LEN - i; j++) {
			if (a[j - 1] > a[j]) {
				Swap(a, j - 1, j);
				flag = 1;
			}
		}
	}
}

//QuickSort快速排序，复杂度O(nlogn)
//@param		枢轴值
void QuickSort(int *a)//驱动程序
{
	QSort(a, 0, LEN - 1);
}

void QSort(int *a, int left, int right)
{
	int pivot;
	if ((right - left) > MINI_ARRAY)
	{
		while (left < right)
		{
			pivot = Partition(a, left, right);

			QSort(a, left, pivot - 1);
			//QSort(a, pivot + 1, right);
			left = pivot + 1;		//此处优化了QSort(a, pivot + 1, right);递归，缩减一部分代码

		}
	}
	else
	{
		InsertSort(a, LEN);//小数组使用插入排序
	}
}

int Partition(int *a, int left, int right)
{
	int temp;
	PickMiddle(a, left, right);//保证枢轴值a[left]为较中间值
	temp = a[left];			//挖坑
	while (left < right) {
		while (left < right && a[right] >= temp) {
			right--;
		}
		a[left] = a[right];//小的值赋到最左

		while (left < right && a[left] <= temp) {
			left++;
		}
		a[right] = a[left];//大的值赋到最右
	}

	a[left] = temp;			//填坑
	return left;
}

void PickMiddle(int *a, int left, int right)
{
	int middle = (left + right) / 2;

	if (a[left] > a[right])
	{
		Swap(a, left, right);
	}
	if (a[middle] > a[right])
	{
		Swap(a, middle, right);
	}
	if (a[left] > a[middle])
	{
		Swap(a, left, middle);
	}
}

//希尔排序，复杂度O(n^(3/2))  
//分组直接插入排序，又称缩小增量排序
//@param	gap		分组（步长可改，此处为2）
void ShellSort(int *a)
{
	int i, j, gap;
	for (gap = LEN / 2; gap > 0; gap /= 2)
		for (i = gap; i < LEN; i++)
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
				Swap(a, j, j + gap);
}

//插入排序，复杂度O(n^2)
//将a[j]插入到前面a[0…j-1]的有序区间
void InsertSort(int *a, int len)
{
	int i, j;

	for (i = 1; i < len; i++)
		for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)//a[j]前一个数据a[j-1] > a[j]
			Swap(a, j, j + 1);//交换a[j]和a[j-1]，再j--直到a[j-1]<= a[j]
}

//选择排序，复杂度O(n^2)  
//从无序区选一个最小的元素直接放到有序区的最后
//@param	min		最小值
void SelectSort(int *a)
{
	int min;

	for (int i = 0; i<LEN; i++) {
		min = i;
		for (int j = i + 1; j<LEN; j++) {
			if (a[j] < a[min])
				min = j;
			Swap(a, i, min);
		}
	}
}


//归并排序（递归式），复杂度O(nlogn)，  
//采用分治法（ Divide and Conquer），先递归地分解数列，再合并数列

//单趟排序
void Merge(int *a, int *tmp, int first, int mid, int last)
{
	int i = first;
	int j = mid + 1;
	int k = first;
	while (i != mid + 1 && j != last + 1)
	{
		if (a[i] > a[j])
			tmp[k++] = a[j++];
		else
			tmp[k++] = a[i++];
	}
	while (i != mid + 1)
	{
		tmp[k++] = a[i++];
	}
	while (j != last + 1)
	{
		tmp[k++] = a[j++];
	}
	for (i = first; i <= last; i++)
		a[i] = tmp[i];
}

//三数求中法,避免用最后一位比较时最后一位是最大值或用第一位比较时第一位是最小值，降低了时间复杂度。 
int ThreeMid(int *a, int left, int right)//找首位，末尾和中点中中间的数
{
	int mid = left + ((right - left) >> 1);
	while (left < right)
	{
		if (a[left] < a[right])
		{
			if (a[mid] < a[left])
				return left;
			else if (a[right] < a[mid])
				return right;
			else
				return mid;
		}
		if (a[left] > a[right])
		{
			if (a[mid] < a[right])
				return right;
			else if (a[mid] > a[left])
				return left;
			else
				return mid;
		}
	}
	return mid;
}

//归并函数
void MSort(int *a, int *tmp, int first, int last)
{
	int mid;
	if (first < last)
	{
		mid = ThreeMid(a, first, last);
		MSort(a, tmp, first, mid);
		MSort(a, tmp, mid + 1, last);
		Merge(a, tmp, first, mid, last);
	}
}

//驱动函数
void MergeSort(int *a)
{
	int tmp[LEN];

	MSort(a, tmp, 0, LEN - 1);
}

//堆排序 ,复杂度O(nlogn)  
//建堆
void AdjustDown(int *a, int index, int n)
{
	int parent = index;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child < n && a[child] < a[child + 1])
			child++;
		if (child < n && a[child] > a[parent])
		{
			Swap(a, parent, child);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
	child = parent;
}
//堆排序
void HeapSort(int *a)
{
	for (int i = LEN / 2 - 1; i >= 0; --i)
	{
		AdjustDown(a, i, LEN);
	}
	for (int j = LEN - 1; j>0; --j)
	{
		Swap(a, j, 0);
		AdjustDown(a, 0, j);
	}
	if (a[0] > a[1])
		Swap(a, 0, 1);
}
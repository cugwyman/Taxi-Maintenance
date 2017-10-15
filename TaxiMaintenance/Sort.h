#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

#define MINI_ARRAY 8//小数组判断阈值
#define LEN 10

void Swap(int *a, int i, int j);
void SwapWithoutTemp(int *a, int i, int j);
void PrintArr(int *a);
void QuickSort(int *a);
void QSort(int *a, int left, int right);
int Partition(int *a, int left, int right);
void PickMiddle(int *a, int left, int right);
void BubbleSort(int *a);
void ShellSort(int *a);
void InsertSort(int *a, int len);
void SelectSort(int *a);
void Merge(int *a, int *tmp, int first, int mid, int last);
int ThreeMid(int *a, int left, int right);
void MSort(int *a, int *tmp, int first, int last);
void MergeSort(int *a);
void HeapSort(int *a);
void AdjustDown(int *a, int index, int n);

#endif
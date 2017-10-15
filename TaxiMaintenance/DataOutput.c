#include "DataOutput.h"

/******
Function:	dataOutput()
Description:���
Calls:		dataSort();
Called By:	main();	
******/
void dataOutput(void)
{
	int i = 1;
	int j = 1;
	int CntBrandTime = 1;

	dataSort();
	printf("Reminder\n");
	printf("==================\n");
	//print time maintenance
	printf("\n* Time - related maintenance coming soon...\n");
	while (j <= CntTimeMaintain)
	{
		while (strcmp(BrandTimeMaintain[i], BrandTimeMaintain[i+1]) == 0 && i < CntTimeMaintain)
			/*(i < CntTimeMaintain)*/
		{
			//if (strcmp(BrandTimeMaintain[i-1], BrandTimeMaintain[i]) == 0)
			{
				i++;
				j = i - 1;
				CntBrandTime++;
			}
		}
		printf("%s: %d (", BrandTimeMaintain[i], CntBrandTime);
		while(CntBrandTime--)
			printf("%s", NumTimeMaintain[i - CntBrandTime]);
		printf(")\n");
		i++;
		j++;
		CntBrandTime = 1;
	}
	i = 1;
	j = 1;
	//print distance maintenance
	printf("\n* Distance-related maintenance coming soon...\n");
	while (j <= CntDistanceMaintain)
	{
		while (BrandDistanceMaintain[i] == BrandDistanceMaintain[i + 1] && i < CntDistanceMaintain)
		{
			i++;
			j = i - 1;
			CntBrandTime++;
		}
		printf("%s: %d (", BrandDistanceMaintain[i], CntBrandTime);
		while (CntBrandTime--)
			printf("%s", NumDistanceMaintain[i - CntBrandTime]);
		printf(")\n");
		i++;
		j++;
		CntBrandTime = 1;
	}
	i = 1;
	j = 1;
	//print write-off maintenance
	printf("\n* Write-off coming soon...\n");
	while (j <= CntWriteOff)
	{
		while (BrandWriteOff[i] == BrandWriteOff[i + 1] && i < CntWriteOff)
		{
			i++;
			j = i - 1;
			CntBrandTime++;
		}
		printf("%s: %d (", BrandWriteOff[i], CntBrandTime);
		while (CntBrandTime--)
			printf("%s", NumWriteOff[i - CntBrandTime]);
		printf(")\n");
		i++;
		j++;
		CntBrandTime = 1;
	}
	i = 1;
	j = 1;


}

/******
Function:	dataSort()
Description:��������
Calls:		insertSort();
Called By:	dataOutput();
******/
void dataSort(void)
{
	insertSort(BrandWriteOff, NumWriteOff, CntWriteOff);//С����ʹ�ò�������
	insertSort(BrandDistanceMaintain, NumDistanceMaintain, CntDistanceMaintain);
	insertSort(BrandTimeMaintain, NumTimeMaintain, CntTimeMaintain);
}

/******
Function:	insertSort()
Description:�������򣬸��Ӷ�O(n^2)����a[j]���뵽ǰ��a[0��j-1]����������
Calls:		charSwap();
Called By:	dataSort();
******/
void insertSort(char *a[], char *b[], int len)
{
	int i, j;

	for (i = 1; i < len; i++)
	{
		for (j = i; j > 0 && (strcmp(a[j], a[j + 1]) > 0); j--)//a[j]ǰһ������a[j-1] > a[j]
		{
			charSwap(a, j, j + 1);//����a[j]��a[j-1]����j--ֱ��a[j-1]<= a[j]
			charSwap(b, j, j + 1);
		}
	}
}

/******
Function:	charSwap()
Description:��������
Calls:		;
Called By:	insertSort();
Input:		char *a[], ָ������� i ��, ָ������� j ��
Output:		whole Car structure
******/
void charSwap(char *a[], int i, int j) 
{
	char *temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


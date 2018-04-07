#include "DataOutput.h"

/******
Function:	dataOutput()
Description:�����Ϣ
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
	//TODO ��������������������Է�װ�����ٳ��ԡ�
	//print time maintenance
	printf("\n* Time - related maintenance coming soon...\n");
	while (j <= CntTimeMaintain)
	{
		while (BrandTimeMaintain[i + 1] && strcmp(BrandTimeMaintain[i], BrandTimeMaintain[i + 1]) == 0)
		{
			i++;
			j = i;
			CntBrandTime++;
		}
		printf("%s: %d (%s", BrandTimeMaintain[i], CntBrandTime, NumTimeMaintain[i - CntBrandTime + 1]);
		while(--CntBrandTime)
			printf(", %s", NumTimeMaintain[i - CntBrandTime + 1]);
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
		while (BrandDistanceMaintain[i + 1] && strcmp(BrandDistanceMaintain[i], BrandDistanceMaintain[i + 1]) == 0)
		{
			i++;
			j = i;
			CntBrandTime++;
		}
		printf("%s: %d (%s", BrandDistanceMaintain[i], CntBrandTime, NumDistanceMaintain[i - CntBrandTime + 1]);
		while (--CntBrandTime)
			printf(", %s", NumDistanceMaintain[i - CntBrandTime + 1]);
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
		while (BrandWriteOff[i + 1] && strcmp(BrandWriteOff[i], BrandWriteOff[i + 1]) == 0)
		{
			i++;
			j = i;
			CntBrandTime++;
		}
		printf("%s: %d (%s", BrandWriteOff[i], CntBrandTime, NumWriteOff[i - CntBrandTime + 1]);
		while (--CntBrandTime)
			printf(", %s", NumWriteOff[i - CntBrandTime + 1]);
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
Description:��������С����ʹ�ò�������
Calls:		insertSort();
Called By:	dataOutput();
******/
void dataSort(void)
{
	insertSort(BrandWriteOff, NumWriteOff, CntWriteOff);
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


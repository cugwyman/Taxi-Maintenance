#ifndef  _DATAANALYSE_H
#define  _DATAANALYSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataInput.h"

struct data
{
	int Year;
	int Month;
	int Day;
	char *Num;
	char *Brand;
	long Distance;
	char *BigRepair;
};

extern int BigRepair;
extern int TimeMaintain;
extern int DistanceMaintain;
extern int WriteOff;
extern int CntWriteOff;
extern int CntDistanceMaintain;
extern int CntTimeMaintain;
extern char *BrandWriteOff[10];//���ϳ���Ʒ��ָ������
extern char *BrandDistanceMaintain[10];//��̱���Ʒ��ָ������
extern char *BrandTimeMaintain[10];//��ʱ����Ʒ��ָ������
extern char *NumWriteOff[10];//���ϳ�������ָ������
extern char *NumDistanceMaintain[10];//��̱�������ָ������
extern char *NumTimeMaintain[10];//��ʱ��������ָ������

void dataAnalyse(void);
int isBigRepair(void);
int isTimeMaintain(void);
int isDistanceMaintain(void);
int isWriteOff(void);
int getDayMax(void);
int getDayMin(void);
time_t convert(int year, int month, int day);
#endif // ! _DATAANALYSE_H

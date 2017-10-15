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
extern char *BrandWriteOff[10];//报废车辆品牌指针数组
extern char *BrandDistanceMaintain[10];//里程保养品牌指针数组
extern char *BrandTimeMaintain[10];//定时保养品牌指针数组
extern char *NumWriteOff[10];//报废车辆车号指针数组
extern char *NumDistanceMaintain[10];//里程保养车号指针数组
extern char *NumTimeMaintain[10];//定时保养车号指针数组

void dataAnalyse(void);
int isBigRepair(void);
int isTimeMaintain(void);
int isDistanceMaintain(void);
int isWriteOff(void);
int getDayMax(void);
int getDayMin(void);
time_t convert(int year, int month, int day);
#endif // ! _DATAANALYSE_H

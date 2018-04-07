#include "DataAnalyse.h"
#include <time.h>

struct tm Info;

int BigRepair;
int TimeMaintain;
int DistanceMaintain;
int WriteOff;
int CntWriteOff;
int CntDistanceMaintain;
int CntTimeMaintain;
char *BrandWriteOff[10];			//报废车辆品牌指针数组
char *BrandDistanceMaintain[10];	//里程保养品牌指针数组
char *BrandTimeMaintain[10];		//定时保养品牌指针数组
char *NumWriteOff[10];				//报废车辆车号指针数组
char *NumDistanceMaintain[10];		//里程保养车号指针数组
char *NumTimeMaintain[10];			//定时保养车号指针数组

/******
Function:	dataAnalyse()
Description:数据分析
Calls:		getSubmitDate();
Called By:	dataInput();
Return:		void
******/
void dataAnalyse(void)
{
	BigRepair = isBigRepair();
	TimeMaintain = isTimeMaintain();
	DistanceMaintain = isDistanceMaintain();
	WriteOff = isWriteOff();
	if (WriteOff)
	{
		CntWriteOff++;
		BrandWriteOff[CntWriteOff] = Car.Brand;
		NumWriteOff[CntWriteOff] = Car.Num;
		//printf("WriteOff : %s %d %s\n", BrandWriteOff[CntWriteOff], CntWriteOff, NumWriteOff[CntWriteOff]);
	}
	else if (DistanceMaintain)
	{
		CntDistanceMaintain++;
		BrandDistanceMaintain[CntDistanceMaintain] = Car.Brand;
		NumDistanceMaintain[CntDistanceMaintain] = Car.Num;
		//printf("DistanceMaintain : %s %d %s\n", BrandDistanceMaintain[CntDistanceMaintain], \
		//		CntDistanceMaintain, NumDistanceMaintain[CntDistanceMaintain]);
	}
	else if (TimeMaintain)
	{
		CntTimeMaintain++;
		BrandTimeMaintain[CntTimeMaintain] = Car.Brand;
		NumTimeMaintain[CntTimeMaintain] = Car.Num;
		//printf("TimeMaintain : %s %d %s\n", BrandTimeMaintain[CntTimeMaintain], \
		//		CntTimeMaintain, NumTimeMaintain[CntTimeMaintain]);
	}
}

/******
Function:	isBigRepair()
Description:判断大修
Calls:		strcmp();
Called By:	dataAnalyse();
Return:		1（大修）0（无修）
******/
int isBigRepair(void)
{
	return (strcmp(Car.BigRepair, "F"));//字符串比较，s1>s2=1;s1=s2=0,s1<s2=-1
}

/******
Function:	isTimeMaintain()
Description:判断定时保养
Calls:		;
Called By:	dataAnalyse();
Return:		1（定时）0（无需）
******/
int isTimeMaintain(void)
{
	int SubYear, SubMonth, SubDay;

	SubYear = Submit.Year - Car.Year;
	SubMonth = Submit.Month - Car.Month;
	SubDay = Submit.Day - Car.Day;
	if (BigRepair)
	{
		if ((SubYear >= 1 && SubMonth < 0 && \
			(((Submit.Month + 12 - Car.Month) >= 2) || \
			(((Submit.Month + 12 - Car.Month) == 1) && SubDay >= 0))) || \
			SubMonth >= 3 || (SubMonth == 2 && SubDay >= 0)) 
			return 1;
	}
	else if (SubYear < 3)
	{
		if ((SubMonth == 11 && SubDay >= 0) || \
			(SubYear > 0 && SubMonth < 0 && \
			(((Submit.Month + 12 - Car.Month) >= 11) || \
				(((Submit.Month + 12 - Car.Month) == 10) && SubDay >= 0))))
			return 1;
		
	}
	else if (SubYear >= 3)
	{
		if (SubMonth >= 6 || (SubMonth == 5 && SubDay >= 0) || \
			(SubMonth < 0 && ((Submit.Month + 12 - Car.Month) >= 5 || \
			(((Submit.Month + 12 - Car.Month) == 4) && SubDay >= 0))))
			return 1;
	}
	return 0;
}

/******
Function:	isDistanceMaintain()
Description:判断里程保养
Calls:		;
Called By:	dataAnalyse();
Return:		1（定时）0（无需）
******/
int isDistanceMaintain(void)
{
	if (Car.Distance % 10000 == 0 || Car.Distance % 10000 >= 9500)
		return 1;
	else
		return 0;
}

/******
Function:	isWriteOff()
Description:判断里程保养
Calls:		;
Called By:	dataAnalyse();
Return:		1（定时）0（无需）
******/
int isWriteOff(void)
{
	int SubYear, SubMonth, SubDay;
	int RunDay;

	SubYear = Submit.Year - Car.Year;
	SubMonth = Submit.Month - Car.Month;
	SubDay = Submit.Day - Car.Day + 1;
	RunDay = SubYear * 365 + SubMonth * 12 + SubDay;

	//int RunDayMax, RunDayMin;

	//RunDayMax = getDayMax();
	//RunDayMin = getDayMin();
	if (BigRepair)
	{
		//if (RunDayMax >= 1095 && RunDayMin <= 1095)
		if(RunDay >= (1095 - Car.Day -30) && RunDay < 1095)
			return 1;
	}
	//else if (RunDayMax >= 2190 && RunDayMin <= 2190)
	else if (RunDay >= (2190 - Car.Day - 30) && RunDay < 2190)
		return 1;
	return 0;
}

time_t convert(int year, int month, int day)
{
	Info.tm_year = year - 1900;
	Info.tm_mon = month - 1;
	Info.tm_mday = day;
	return mktime(&Info);
}

int getDayMax(void)
{
	int FromSecond = (int)convert(Car.Year, Car.Month, Car.Day);
	int ToSecond = (int)convert(Submit.Year, Submit.Month+1, Submit.Day);
	return (ToSecond - FromSecond) / 24 / 3600;
}

int getDayMin(void)
{
	int FromSecond = (int)convert(Car.Year, Car.Month, Car.Day);
	int ToSecond = (int)convert(Submit.Year, Submit.Month-1, Submit.Day+1 );
	return (ToSecond - FromSecond) / 24 / 3600;
}
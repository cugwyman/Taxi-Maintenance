#include "DataInput.h"

#define N 128		//读取行数
#define M 1024		//每行字数

int CurrentLine;            //当前读取的行
char StrLine[N][M];			//存储每行字符串
struct data Submit;			//提交日期结构体
struct data Car;			//车辆信息结构体

/******
Function:	dataInput()
Description:读取输入
Calls:		getSubmitDate(); getCarData(); dataAnalyse();
Called By:	main();
Input:		StrLine[N][M],
Output:		SumLine,
Return:		void
******/

void dataInput(void)
{
	while (strlen(gets_s(StrLine[CurrentLine], 1024)) > 0 )
	{
		if (CurrentLine < N)
		{
			if (CurrentLine == 0)
			{
				getSubmitDate();
			}
			else
			{
				getCarData();
				dataAnalyse();
			}
			CurrentLine++;
		}
		else
			printf("Too much data!");
	}
}

/******
Function:	getSubmitDate()
Description:获取提交日期
Calls:		strtok_s(), atoi();
Called By:	dataInput();
Input:		
Output:		Submit.Year, Submit.Month, Submit.Day,
Return:		void
******/
void getSubmitDate(void)
{
	char *PtrRemain;
	char *PtrPre;

	PtrPre = strtok_s(StrLine[0], " ", &PtrRemain);
	Submit.Year = atoi(strtok_s(NULL, "/", &PtrRemain));
	Submit.Month = atoi(strtok_s(NULL, "/", &PtrRemain));
	Submit.Day = atoi(strtok_s(NULL, "/", &PtrRemain));
}

/******
Function:	getCarData()
Description:获取车辆信息
Calls:		strtok_s(), atoi();
Called By:	dataInput();
Input:
Output:		whole Car structure
Return:		void
******/
void getCarData(void)
{
	char *PtrRemain;
	char *PtrDate;

	Car.Num = strtok_s(StrLine[CurrentLine], "|", &PtrRemain);
	PtrDate = strtok_s(NULL, "|", &PtrRemain);
	Car.Brand = strtok_s(NULL, "|", &PtrRemain);
	Car.Distance = atoi(strtok_s(NULL, "|", &PtrRemain));
	Car.BigRepair = (strtok_s(NULL, "|", &PtrRemain));
	Car.Year = atoi(strtok_s(PtrDate, "/", &PtrRemain));
	Car.Month = atoi(strtok_s(NULL, "/", &PtrRemain));
	Car.Day = atoi(strtok_s(NULL, "/", &PtrRemain));
}
#include "DataInput.h"

#define N 128 //读取行数
#define M 1024//每行字数

int CurrentLine;             //当前读取的行
int SumLine;				//读取总行数,从0开始
char StrLine[N][M];
struct data Submit;
struct data Car;

/******
Function:	dataInput()
Description:读取输入
Calls:		getSubmitDate();
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
			//printf("%s", StrLine[CurrentLine]); 
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
	SumLine = CurrentLine - 1;
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
	//printf("%d\n", Submit.Year);
	//printf("%d\n", Submit.Month);
	//printf("%d\n", Submit.Day);
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
	//printf("%s\n", Car.CarNum);
	//printf("%d\n", Car.Year);
	//printf("%d\n", Car.Month);
	//printf("%d\n", Car.Day);
	//printf("%s\n", Car.Brand);
	//printf("%d\n", Car.Distance);
	//printf("%s\n", Car.BigRepair);
}

//char DataTest1 = { 
//"
//SubmitDate: 2030/09/01
//CAR0001|2025/04/05|Porsche|10000|F
//CAR0002|2029/10/14|Porsche|9000|F
//CAR0003|2026/08/17|Porsche|13000|F
//CAR0004|2027/11/01|BYD|23000|T
//CAR0005|2027/01/11|BYD|19500|F
//CAR0006|2029/07/01|Audi|10001|T
//CAR0007|2028/04/19|Ford|9800|F
//CAR0008|2027/07/10|Ford|15000|T
//CAR0009|2024/10/22|Ford|90300|F
//"
//}

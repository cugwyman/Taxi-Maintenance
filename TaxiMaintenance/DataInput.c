#include "DataInput.h"

#define N 128		//��ȡ����
#define M 1024		//ÿ������

int CurrentLine;            //��ǰ��ȡ����
char StrLine[N][M];			//�洢ÿ���ַ���
struct data Submit;			//�ύ���ڽṹ��
struct data Car;			//������Ϣ�ṹ��

/******
Function:	dataInput()
Description:��ȡ����
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
Description:��ȡ�ύ����
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
Description:��ȡ������Ϣ
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
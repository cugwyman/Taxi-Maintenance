/*************************************************

Program name:	Taxi Maintenance Service
				出租车保养服务

Author:			梁植源 ( Wyman )
Version:		V 1.0
Date:  			2017.10.15
Description:	1. ThoughtWorks homework
				2. Used C	
				3. Read more in Readme.md
				
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataInput.h"
#include "DataAnalyse.h"
#include "DataOutput.h"

int main()
{
	dataInput();
	dataOutput();
	//system("pause");
	return 0;
}


/*	暂定运行主程序，复制以下输入测试功能	*/
/*	Test 1
SubmitDate: 2030/09/01
CAR0001|2025/04/05|Porsche|10000|F
CAR0002|2029/10/14|Porsche|9000|F
CAR0003|2026/08/17|Porsche|13000|F
CAR0004|2027/11/01|BYD|23000|T
CAR0005|2027/01/11|BYD|19500|F
CAR0006|2029/07/01|Audi|10001|T
CAR0007|2028/04/19|Ford|9800|F
CAR0008|2027/07/10|Ford|15000|T
CAR0009|2024/10/22|Ford|90300|F
*/

/*	Test 2
SubmitDate: 2050/05/01
CAR0001|2044/05/01|Volkswagen|65535|F
CAR0002|2044/05/03|BMW|100001|F
CAR0003|2047/05/02|Mercedes-Benz|37789|T
CAR0004|2047/05/03|Honda|59908|T
CAR0005|2049/12/10|Peugeot|49999|F
CAR0006|2046/11/15|Jeep|2000|F
CAR0007|2046/11/16|Jeep|5000|F
*/
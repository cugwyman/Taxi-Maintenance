#ifndef _DATAINPUT_H
#define _DATAINPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataAnalyse.h"

extern struct data Submit;
extern struct data Car;

void dataInput(void);
void getSubmitDate(void);
void getCarData(void);
#endif // !_DATAINPUT_H

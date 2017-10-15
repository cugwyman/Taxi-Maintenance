#ifndef _DATAOUTPUT_H
#define _DATAOUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataInput.h"
#include "DataAnalyse.h"
#include "Sort.h"

void dataOutput(void);
void dataSort(void);
void insertSort(char *a[], char *b[], int len);
void charSwap(char *a[], int i, int j);
#endif // !_DATAOUTPUT_H

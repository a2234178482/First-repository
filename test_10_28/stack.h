#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int STDataType;
typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

void STPush(ST* pst);
void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);

int STSize(ST* pst);
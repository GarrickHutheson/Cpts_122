#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stackNode {
	struct stackNode * pNext;
	int data;
}Node;
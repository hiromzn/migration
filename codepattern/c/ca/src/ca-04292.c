#include <stdio.h>
unsigned int value = 0x03020100;
unsigned int *ptr = &value;
unsigned char charVal;
void foo()
{
	charVal = *(unsigned char *)ptr;
}

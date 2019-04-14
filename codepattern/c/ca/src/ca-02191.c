#include <stdio.h>

int main(void)
{
const int i = 5;
int j;
    j = (const int)i;
    printf("%d\n", j);
    return(0);
} 


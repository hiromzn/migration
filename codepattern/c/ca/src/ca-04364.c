#include <stdio.h>
int main(int argc, char **argv)
{
    int *p;
    short q = 0x0123;
    p = (char *)&q;
    printf("%d\n", *p);
    return(0);
}

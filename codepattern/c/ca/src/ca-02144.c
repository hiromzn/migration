#include <stdio.h>

typedef char* addr;

int main(int argc, char **argv)
{
    addr data = "0x1";
    int bar = data;
    printf("%d",bar);
    return 0;
}

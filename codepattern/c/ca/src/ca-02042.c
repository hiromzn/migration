#include <stdio.h>

#define DT 10
typedef char* caddr;

int main(int argc, char **argv)
{
    caddr data = "0x1";

    if (data == DT)
    {
        return 1;
    }
    return 0;
} 


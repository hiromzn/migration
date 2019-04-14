#include <stdio.h>

typedef char * addr;
int foo(int a);

int foo(int a) 
{
    return a;
}
int main(int argc, char **argv)
{
    addr data = "0x1";
    foo(data);
    return 0;
}



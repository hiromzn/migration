#include <stdio.h>

void foo(int a);

void foo(int a)
{
        printf("hoge\n");
}

int main(int argc, char **argv)
{
        int a=1;
        foo(a);
        return(0);
}

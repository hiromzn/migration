#include <stdio.h>

int main(int argc, char **argv)
{
    printf("data %s [%.0*ld]\n","aaa", 10);  // G2226
    printf("%2 s\n", "foo");                 // G30107
    return(0);
}

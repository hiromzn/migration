#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%c", '\z');
    // printf("•\\Ž¦\n"); // if '-Y' option is used on HP-UX compile.
    return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    int i, j;

    // On HP-UX : #2767-D and On Linux : G2767
    i = (int)&j;

    // On HP-UX : no worning, but on Linux : G2767
    i= (int)NULL;
    printf("%x\n", i);

    return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
        #if DEBUG
                printf("ue\n");
        #else
                printf("shat\n");
        #endif
}

#include <stdio.h>

void sub(int cnt);

void sub(int cnt)
{
        int     i;
        int     x;

        for(i=0; i<cnt; i++)
        {
                if(i > 10)
                {
                        x = 1;
                }
        }

        if(x == 0)
        {
                printf("zero\n");
        }
}

int main(int argc, char *argv[])
{
        sub(1);

        return(0);
}

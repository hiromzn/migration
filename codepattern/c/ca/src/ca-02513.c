#include <stdio.h>
#include <signal.h>

int main(int argc, char **argv)
{
  // #2513-D -> G3235
  int ret = ret=signal(SIGCHLD, SIG_DFL);

     double d=1.0;
     int *i;
  // #2513-D -> G4212
        i=&d;

     printf("%d %d\n", ret, *i);
    return(0);
}

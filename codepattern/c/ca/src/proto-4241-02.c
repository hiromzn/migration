#include <stdio.h>
static void sub();
int main(int argc, char **argv)
{
   sub(10);
   return(0);
}
static void sub(int i)
{
   printf("%d\n", i);
   return;
}


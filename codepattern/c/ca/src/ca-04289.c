#include <stdio.h>
int main(int argc, char **argv)
{
  union _u_subst 
  {
    char           c_moji[2];
    unsigned short us_code;
  } u_subst = {"A"};

  printf("%d\n", u_subst.us_code);

  return(0);
}

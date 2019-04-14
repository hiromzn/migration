#include <stdio.h>

int	main(int argc, char **argv)
{

union U {
  struct {
    int a;
    double b;
  };  // invalid: anonymous struct
  struct {
    char* c;
    unsigned d;
  };  // invalid: anonymous struct
};

	return 0;
}

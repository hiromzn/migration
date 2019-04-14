#include <stdio.h>

typedef struct {
    int field1;
    double field2;
} str;

int main(int argc, char **argv)
{
	str x;
	x.field1=1;
	x.field2=1.1;

	printf("%d %f\n", x.field1, x.field2);
	return(0);
}

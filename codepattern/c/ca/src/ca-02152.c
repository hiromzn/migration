#include <stdio.h>

#define         MSG_ID      3
void strput(char *a, char *b, char *c);

int main(int argc, char **argv)
{
    strput( MSG_ID, "msg1", "msg2" );
    return 0;
}

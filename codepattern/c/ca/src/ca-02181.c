#include <stdio.h>

int main(int argc, char **argv)
{
   char buf[24];
   char *p="foo";

    // On HP-UX : #2181-D and On Linx G31000
    snprintf(buf, sizeof(buf), "%.*s", sizeof(buf)-1, p);
    printf("%s\n", buf);

    // On HP-UX : #2181-D and On Linx G31004
   printf("%d\n", 2.0);
        return(0);
}

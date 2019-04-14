#include <stdio.h>

int sample(char *s);

int main(int argc, char **argv)
{
    sample("abc");
    return 0;
}

int sample(const char *s)
{
    printf("%s\n", s);
    return 0;
}

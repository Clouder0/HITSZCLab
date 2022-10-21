#include <ctype.h>
#include <stdio.h>

int main()
{
    char c = getchar();
    while (1) {
        while (!isdigit(c) && c != EOF)
            c = getchar();
        if (c == EOF)
            break;
        int num = 0;
        while (isdigit(c))
            num = num * 10 + c - '0', c = getchar();
        printf("%10d\n", num);
    }
    return 0;
}
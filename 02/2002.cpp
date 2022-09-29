// 交叉相乘

#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d/%d,%d/%d", &a, &b, &c, &d);
    int cmp = a * d - b * c;
    printf("%d/%d ", a, b);
    if (cmp > 0) putchar('>');
    else if (cmp == 0) putchar('=');
    else putchar('<');
    printf(" %d/%d", c, d);
}
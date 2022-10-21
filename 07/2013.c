/*
高精度内容
*/

#include <stdio.h>
int A[100], B[100], C[100], alen, blen;
int main()
{
    char c = getchar();
    while (c >= '0' && c <= '9') {
        A[++alen] = c - '0';
        c = getchar();
    }
    for (int i = 1; i <= alen; ++i)
        C[i] = A[alen - i + 1];
    for (int i = 1; i <= alen; ++i)
        A[i] = C[i];
    while (!(c >= '0' && c <= '9'))
        c = getchar();
    while (c >= '0' && c <= '9') {
        B[++blen] = c - '0';
        c = getchar();
    }
    for (int i = 1; i <= blen; ++i)
        C[i] = B[blen - i + 1];
    for (int i = 1; i <= blen; ++i)
        B[i] = C[i];
    for (int i = 1; i <= blen; ++i) {
        A[i] += B[i];
        if (A[i] >= 10)
            A[i + 1]++, A[i] -= 10;
    }
    alen = (alen < blen ? blen : alen);
    while (A[alen + 1] > 0)
        ++alen;
    for (int i = alen; i; --i)
        putchar('0' + A[i]);
    return 0;
}
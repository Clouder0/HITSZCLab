#include <stdio.h>
#define maxn 5100
int n, m, a[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);
    for (int j = 1; j <= m; puts(""), ++j)
        for (int i = 1; i <= n; ++i)
            printf("%d ", a[i][j]);
    return 0;
}
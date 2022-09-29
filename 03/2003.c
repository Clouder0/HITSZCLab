// 拓展了解：使用欧拉筛线性求素数

#include <stdio.h>
#define MAXN 1100
int primes[MAXN], notprime[MAXN], cnt;
int m, n, a[MAXN];
int main()
{
    notprime[1] = 1;
    for (int i = 2; i < 1000; ++i)
    {
        if (!notprime[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] < 1000; ++j)
        {
            notprime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1, x; i <= n; ++i)
            scanf("%d", &x), sum += !notprime[x] * x;
        printf("%d\n", sum);
    }
    return 0;
}
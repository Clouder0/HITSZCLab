// 这个递归的复杂度令人感叹

#include <stdio.h>
const int MOD = 32767;

int pell(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 2;
    return (2 * pell(x - 1) + pell(x - 2)) % MOD;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", pell(n));
    }
    return 0;
}
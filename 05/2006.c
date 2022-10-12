// 根据数据范围，直接使用桶是最为简洁方便的

#include <stdio.h>
#define MAXN 1100
int n, cnt[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i)
    scanf("%d", &x), cnt[x]++;
  int num = 0;
  for (int i = 1; i <= 1000; ++i)
    if (cnt[i])
      ++num;
  printf("%d\n", num);
  for (int i = 1; i <= 1000; ++i)
    if (cnt[i])
      printf("%d ", i);
  return 0;
}
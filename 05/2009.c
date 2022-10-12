/*
设第一个三位数是 x，第二个则为 2x，第三个是 3x.
显然 x \in [100,333]，枚举 x，然后检验是否满足题意即可
或者直接打表输出：
192,384,576
219,438,657
273,546,819
327,654,981
*/

#include <stdio.h>
int cnt[10];
int check(int x, int y, int z) {
  for (int i = 1; i <= 9; ++i)
    cnt[i] = 0;
  while (x)
    ++cnt[x % 10], x /= 10;
  while (y)
    ++cnt[y % 10], y /= 10;
  while (z)
    ++cnt[z % 10], z /= 10;
  for (int i = 1; i <= 9; ++i)
    if (cnt[i] != 1)
      return 0;
  return 1;
}
int main() {
  for (int x = 100; x <= 333; ++x) {
    int y = x * 2, z = x * 3;
    if (check(x, y, z))
      printf("%d,%d,%d\n", x, y, z);
  }
  return 0;
}
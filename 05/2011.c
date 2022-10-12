// 先存放到桶里
// 平均数计算和即可
// 中位数则从小到大遍历桶，累积数字直到超过一半
// 需要注意中位数有两个的情况
// 众数则遍历桶，找到最大值

#include <stdio.h>
int n, sum, cnt[11];

int Mean() { return sum / n; }

int Median() {
  int past = 0;
  if (n & 1) {
    for (int i = 0; i <= 10; ++i) {
      past += cnt[i];
      if (2 * past > n)
        return i;
    }
  } else {
    int first = -1, second = 0;
    for (int i = 0; i <= 10; ++i) {
      if (!cnt[i])
        continue;
      if (past < n / 2 && past + cnt[i] >= n / 2)
        first = i;
      if (past <= n / 2 && past + cnt[i] > n / 2) {
        second = i;
        return (first + second) >> 1;
      }
      past += cnt[i];
    }
  }
  return -1; // ERROR
}

int Mode() {
  int maxi = 0;
  for (int i = 1; i <= 10; ++i)
    if (cnt[i] > cnt[maxi])
      maxi = i;
  return maxi;
}

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i)
    scanf("%d", &x), cnt[x]++, sum += x;
  printf("Mean=%d\n", Mean());
  printf("Median=%d\n", Median());
  printf("Mode=%d\n", Mode());
  return 0;
}
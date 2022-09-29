// 闰年二月加一即可

#include <stdio.h>
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int y, m, d;
    scanf("请输入日期（年，月，日）\n%d,%d,%d", &y, &m, &d);
    int res = d;
    int lunar = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    days[2] += lunar;
    for (int i = 1; i < m; ++i)
        res += days[i];
    printf("\n%d月%d日是%d年的第%d天。", m, d, y, res);
}
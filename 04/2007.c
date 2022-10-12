// 破烂题，OJ 上就不该输出制表符
// 计算 1900 年 1 月 1 日起到当月第一天的日子，从而计算出当月第一天是星期几
// 第一周比较特殊，其他的奉周天就输出一次换行即可
// 没有什么补空格的需求，纯纯的制表符跟在每个日期后面

#include <stdio.h>
int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int is_lunar(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int get_delta_days(int year)
{
    int res = 0;
    for (int i = 1900; i < year; ++i)
        res += 365 + is_lunar(i);
    return res;
}
int main()
{
    int year, month;
    scanf("%d%d", &year, &month);
    days[2] += is_lunar(year);
    puts("Sun\tMon\tTue\tWed\tThu\tFri\tSat");
    int past_days = get_delta_days(year);
    for (int i = 1; i < month; ++i)
        past_days += days[i];
    int week_day = (past_days + 1) % 7;
    for (int i = 0; i < week_day; ++i)
        printf("\t");
    for (int cur = 1; cur <= days[month]; ++cur) {
        printf("%d", cur);
        // if(cur < 10) printf("  ");
        // else putchar(' ');
        printf("\t");
        ++week_day;
        if (week_day == 7)
            putchar('\n'), week_day = 0;
    }
    return 0;
}
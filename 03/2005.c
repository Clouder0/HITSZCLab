// scanf 返回值为合法输入值个数
// 注意分钟必须显示两位，比如 `12:00` 而非 `12:0`
// 注意角度范围不包括 360

#include <stdio.h>
#include <math.h>
const double angle_per_hour = 30.0;
const double angle_per_minute = 6.0;
int main()
{
    int h, m;
input:
    puts("Please input time");
    int num = scanf("%dh%dm", &h, &m);
    if (num != 2) goto input;
    if (!(h >= 0 && h <= 12 && m >= 0 && m <= 60)) goto input;
    double angle = fabs(angle_per_hour * (h + m / 60.0) - angle_per_minute * m);
    if (angle >= 360.0) angle -= 360.0;
    printf("At %d:%.2d the angle is %.1f degrees.\n", h, m, angle);
    return 0;
}
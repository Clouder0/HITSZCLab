// 可以通过相等边数来判定等腰、等边
// 勾股定理判定直角，注意精度要调得比较低

#include <stdio.h>
#include <math.h>
const double EPS = 1e-1;
int eq(double a, double b)
{
    return fabs(a - b) < EPS;
}
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (!(a + b > c && a + c > b && b + c > a))
    {
        puts("不是三角形");
        return 0;
    }
    //    printf("%.7f",c*c);
    int same_edge = eq(a, b) + eq(a, c) + eq(b, c);
    int ht = eq(a * a + b * b, c * c) || eq(a * a + c * c, b * b) || eq(b * b + c * c, a * a);
    if (same_edge == 1) printf("等腰");
    else if (same_edge == 3) printf("等边");
    if (ht) printf("直角");
    if (!same_edge && !ht) printf("一般");
    printf("三角形\n");
    double P = (a + b + c) / 2;
    double S = sqrt(P * (P - a) * (P - b) * (P - c));
    printf("S=%.2f\n", S);
    return 0;
}
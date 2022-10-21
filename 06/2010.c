/*
需要注意，开头的两句废话也是要打印的。。。
*/

#include <stdio.h>
#define N 40
int n, MT[N], EN[N], PH[N], sum[N], Msum, Esum, Psum;
char id[N][13];
int main()
{
    puts("Input the total number of the students(n<40):\nInput student’s ID and score as: MT  EN  PH:");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s%d%d%d", id[i], MT + i, EN + i, PH + i);
    for (int i = 0; i < n; ++i)
        sum[i] = MT[i] + EN[i] + PH[i];
    puts("Counting Result:");
    puts("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER");
    for (int i = 0; i < n; ++i)
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",
            id[i], MT[i], EN[i], PH[i], sum[i], 1.0 * sum[i] / 3);
    for (int i = 0; i < n; ++i)
        Msum += MT[i], Esum += EN[i], Psum += PH[i];
    printf("SumofCourse \t%4d\t%4d\t%4d\t\n", Msum, Esum, Psum);
    printf("AverofCourse\t%4.1f\t%4.1f\t%4.1f\t", 1.0 * Msum / n, 1.0 * Esum / n, 1.0 * Psum / n);
    return 0;
}
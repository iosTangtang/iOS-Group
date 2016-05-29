/* 迭代法求一个数的平方根 */
#define Epsilon 1.0E-6 /*控制解的精度*/
#include<math.h>
main()
{
    float a,x0,x1;
    printf(“请输入要求的数:”);
    scanf(“%f”,&a);
    x0=a/2;
    x1=(x0+a/x0)/2;
    while(fabs(x1-x0)>=Epsilon)
    {
        x0=x1;
        x1=(x0+a/x0)/2;
    }
    printf(“%f的平方根：%f.5\n”,x1);
}
/* 上题的另一种算法 */
#define Epsilon 1.0E-6 /*控制解的精度*/
#include <stdio.h>
#include <math.h>
main()
{
    float num,pre,this;
    do
    {
        scanf(“%f”,&num);/*输入要求平方根的数*/
    }while(num<0);
    if (num==0)
        printf(“the root is 0″);
    else
    {
        this=1;
        do
        {
            pre=this;
            this=(pre+num/pre)/2;
        }while(fabs(pre-this)>Epsilon);/*用解的精度，控制循环次数*/
    }
    printf(“the root is %f”,this);
}
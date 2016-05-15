//调用函数求两数的最大公约数和最小公倍数

#include <stdio.h>
int gongyue(int m,int n)
{
    int r;
    if(m==n)
        return m;
    else
        while((r=m%n)!=0)
        {
            m=n;
            n=r;
        }
    return n;
}
int gongbei(int m,int n)
{
    if(m==n)
        return 0;
    else
        return m*n/gongyue(m,n);
}
void main()
{
    int a,b,i;
    printf("please input two numbers:\n");
    scanf("%d%d",&a,&b);
    i=gongyue(a,b);
    printf("最大公约数为:%d",gongyue(a,b));
    printf("最小公倍数为:%d",gongbei(a,b));
}
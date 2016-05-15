//2.如果有两个数，每一个数的约数之和正好等于对方，则称之为互满数。求出10000以内互满数
//一个数的约数之和等于另一个数
#include<stdio.h>

int yueshu(int f)
{
    int sum=0,i;
    for(i=1;i<f;i++)
        if(f%i==0)
            sum+=i;
    return (sum);
}

int main(void)
{
    int n,i,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=yueshu(i);
        if(s>i && yueshu(s)==i)
            printf("%d %d\n",i,s);
    }
}

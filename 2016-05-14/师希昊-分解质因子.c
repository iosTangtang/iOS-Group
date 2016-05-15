//将一个正整数分解质因数
//例如：输入 90，
//输出  90=2*3*3*5；
//分析，对n进行分解质因数，先找最小质因数看；
//1>如果最小质因数=你，，直接打印
//2>如果最小质因数<n但n能被最小质因数整除，打印最小质因数，并用n/最小质因数，打印

#include<stdio.h>
int main(void)
{
    int n,i;
    printf("please input number\n");
    scanf("%d",&n);
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
        while(n!=i)
        {
            if(n%i==0)
            {
                printf("%d*",i);
                n/=i;
            }
            else
                break;
        }
    }
    printf("%d\n",n);
}

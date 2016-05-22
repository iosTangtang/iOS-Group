//问题：猴子选大王，办法如下：猴子 按1,2,3....n的顺序编号围成一圈，
//从第一个开始按1,2,3...报数，报m的退出，下一个从1开始继续，剩下的猴子就是大王。
#include <stdio.h>
int choose(int n,int m);
int main(void)
{
    int n,m;
    int i,j,p;
    scanf("%d%d",&n,&m);
    p=choose(n,m);
    printf("%d",p);
    return 0;
}
int choose(int n,int m)
{
    int i,sum=0,countOne=n; //表示剩余猴子的个数
    int a[n];
    for(i=0;i<n;i++)
        a[i]=1; //对数组初始化为1；
    i=0;
    while (i<=n)
    {
        
        if (i==n) i=0;
        sum+=a[i];
        if(sum==m)
        {
            sum=a[i]=0;
            countOne--;
            if (countOne==1) break;
        } 
        i++; 
    } 
    for(i=0;i<n;i++) 
        if(a[i]!=0) 
            return i+1; 
} 

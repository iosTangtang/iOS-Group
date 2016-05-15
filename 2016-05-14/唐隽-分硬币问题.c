//设有n种不同面值的硬币，各硬币的面值存于数组T［1:n］中。
//现要用这些面值的硬币来找钱。可以使用的各种面值的硬币个数存于数组Coins［1:n］中。
//对任意钱数0≤m≤20001，设计一个用最少硬币找钱m的方法。

#include<stdio.h>

int T[11],Coins[11],n;
int c[2013],num[2013];

int main(int argc, char* argv[])
{
    int i,j,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;++i)
            scanf("%d%d",&T[i],&Coins[i]);
        scanf("%d",&m);
        for(i=1;i<=m;++i)
            c[i]=0xfffffff;
        c[0]=0;
        for(i=0;i<n;++i)
        {
            for(j=0;j<=m;++j)
                num[j]=0;
            for(j=0;j<=m-T[i];++j)
                if(num[j]<Coins[i]&&c[j]+1<c[j+T[i]])
                {
                    c[j+T[i]]=c[j]+1;
                    num[j+T[i]]=num[j]+1;
                }
        }
        if(c[m]!=0xfffffff)
            printf("%d\n",c[m]);
        else
            printf("-1\n");
    }
    return 0;
}


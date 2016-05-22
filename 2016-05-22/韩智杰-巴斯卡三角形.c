//1.算法
//巴斯卡三角形，这个题主要是求出公式，然后写出格式就好了。由于位数原因，输出不是很规范，忘谅解
#include"studio.h"
#define N 12
int qiuzhi (int n,int r)
{
    int i,p=1;
    for(i=1;i<=r;i++)
    {
        p=p*(n-i+1)/i;
    }
}
main()
{
    int n,r,i;
    for(n=0;n<=N;n++)
    {
        for(r=0;r<=n;r++)
        {
            if(r==0)
            {
                for(i=0;i<=N-n;i++)
                    printf(" ");
            }
            else
                printf(" ");
            printf("%3d",qiuzhi(n,r));
        }
        printf("\n");
    }
}
//巴斯卡三角形：
//1
//1    1
//1    2    1
//1    3    3   1
//1    4    6    4    1
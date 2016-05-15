//算法幻方：
//有一个N阶矩阵，填入N*N个数，使每行，每列，对角线上的数字和相等。
//（我只写了N是奇数的情况，其他小伙伴可以写一下N是偶数的情况）

#include <stdio.h>
#define M 10
void MagicInit(int MS[M][M],int m)      //数组参数实际为指针，可以修改主函数里的数组
{
    ​int i,j;
    ​for(i=0;i<m;i++)
        ​​for(j=0;j<m;j++)
            ​​​MS[i][j]=0;
}
void Magic(int MS[M][M],int m)
{
    ​int x=0,y=m/2,i=1;
    ​MS[x][y]=i;
    ​for(i=2;i<=m*m;i++)
        ​{
            ​​x=(x-1+m)%m;
            ​​y=(y-1+m)%m;
            ​​if(MS[x][y]!=0)
                
                ​​{
                    ​​​x=(x+2)%m;
                    ​​​y=(y+1)%m;
                    ​​}
            ​​MS[x][y]=i;
            ​}
}
void Magicprint (int MS[M][M],int m)
{
    ​int i,j;
    ​for(i=0;i<m;i++)
        ​{
            ​​for(j=0;j<m;j++)
                ​​​printf("%4d",MS[i][j]);
            ​​printf("\n");
            ​}
}
int main(void)
{
    ​int MS[M][M];
    ​int m;
    ​printf("请输入幻阵的阶数0<m<%d,且m为奇数\n",M);
    ​scanf("%d",&m);
    ​MagicInit(MS,m);
    ​Magic(MS,m);
    ​Magicprint(MS,m);
    ​return 0;
}
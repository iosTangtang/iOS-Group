//现有八枚硬币abcdefgh，已知其中一枚是假币，但不知是较轻或较重，如何使用天平以最少的比较次数，决定出那枚是假币，并得知是较轻或较重。
//解法：比较a+b+c和e+f+g,如果相等，则假币必为g或h，我们比较g或h那个较重，如果g较重，再与a比较，如果相等则假币为h，且假币较轻。
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void compare(int coins[],int i,int j,int k);
{
    if(coins[i]>coins[k])
        printf(“\n假币%d较重”,i+1);
        else
            printf(“’\n假币%d较轻”，j+1)；
            }
void eightcoins(int coins[])
{
    if(coins[0]+coins[1]+coins[2]==coins[3]+coins[4]coins[5])
    {
        if(coins[6]>coins[7])
            compare(coins,6,7,0);
        else
            compare(coins,7,6,0)
            }
    else if(coins[0]+coins[1]+coins[2]>coins[3]+coins[4]+coins[5]
    {
        if(Coins[0]+coins[3]==coins[1]+coins[4])
            Compare(coins,2,5,0);
        else if(coins[0]+coins[3]>coins[1]+coins[4])
            compare(coins,0,4,1);
        if(coins[0]+coins[3]<coins[1]+coins[4])
            compare(coins,1,3,0);
    }
            else if(coins[0]+coins[1]+coins[2]<coins[3]+coins[4]+coins[5])
    {
        if(coins[0]+coins[3]==coins[1]+coins[4])
            compare(coins,5,2,0);
        else if(coins[0]+coins[3]>coins[1]+coins[4])
            compare(coins,3,1,0);
        if(coins[0]+coins[3]<coins[1]+coins[4])
            compare(coins,4,0,1);
    }
            }
            Int main(void)
    {
        int coins[8]={0};
        int i;
        srand (time(NULL));
        for（i=0；i<8；i++）
            coins[rand()%8]=i;
        eigetcoins (coins);
        printf(“\n\n列出所有铅笔重量：”)；
        For(i=0;i<8;i++)
        P
        printf (“%d”,coins[i]);
        printf (“\n”);
        return 0;
    }

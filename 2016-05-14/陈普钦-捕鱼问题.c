//题目：A、B、C、D、E五人在某天夜里合伙去捕鱼，到第二天凌晨时都疲惫不堪，
//于是各自找地方睡觉。日上三杆，A第一个醒来，他将鱼分为五份，
//把多余的一条鱼扔掉，拿走自己的一份。B第二个醒来，也将鱼分为五份，
//把多余的一条鱼扔掉拿走自己的一份。C、D、E依次醒来，也按同样的方法拿鱼。问他们台伙至少捕了多少条鱼?
//思路;采用试探的方法。通过循环令试探值n逐步加大，
//用count作为控制标记，每次都满足条件时，count++，当count==5，
//既满足所有的条件时，输出i，即为最少的捕鱼数。

#include"stdio.h"
int main(void)
{
    int i,j,count=0;
    int n;
    for(i=1;i<10000;i++){
        n=i;
        for(j=0;j<5;j++){
            if(n%5==1){
                n=(n-1)*4/5;
                count++;
            }
        }
        if(count==5){
            printf("%5d",i);
            return 0;
        }
        count=0;
    }
    return 0;
}

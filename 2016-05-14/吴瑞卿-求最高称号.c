//很多童鞋喜欢玩一些lol、dota这类游戏，这类游戏有一个特点，在你不死的情况下连续杀人会有不同称号。
//下面输入一组字符，其中只包含K和D，K代表杀敌，D代表死亡，求他最高称号。
//0/1/2 - You are a Foolish Man
//3 - You are on a Killing Spree
//4 - You are Dominating
//5 - You have a Mega-Kill
//6 - You are Unstoppable
//7 - You are Wicked Sick
//8 - You have a M-m-m-m....Monster Kill
//9 - You are Godlike
//10+ - You are Beyond Godlike (Somebody kill him!)

#include <stdio.h>
#include <string.h>
int max(int b[],int n) {
    int max,i,t;
    max=b[0];
    for(i=1;i<n;i++)
        if(max<b[i])
            max=b[i];
    return (max);
}
int main(）
{
    int n,i,j=0,sum=0,a[50],m;
    char str[50];
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++) {
        if(str[i]=='K')
            sum++;
        if(str[i]=='D'||i==n-1) {
            a[j]=sum;
            sum=0;
            j++;
        }
    }
    m=max(a,j);
    if(m==0||m==1||m==2)
        printf("You are a Foolish Man\n");
    else if(m==3)
        printf("You are on a Killing Spree\n");
    else if(m==4)
        printf("You are Dominating\n");
    else if(m==5)
        printf("You have a Mega-Kill\n");
    else if(m==6)
        printf("You are Unstoppable\n");
    else if(m==7)
        printf("You are Wicked Sick\n");
    else if(m==8)
        printf("You have a M-m-m-m....Monster Kill\n");
    else if(m==9)
        printf("You are Godlike\n");
    else
        printf("You are Beyond Godlike (Somebody kill him!)\n");
    return 0;
}
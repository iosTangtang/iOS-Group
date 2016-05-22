#include <stdio.h>

#include <string.h>
int index_KMP(char *s,char *t,int pos);
//利用模式串的t的next函数求t在主串s中的第pos个位置之后的位置的KMP算法（t非空，1<=pos<=Strlength(s)）。
void get_next(char * t,int * next);
//求模式串t的next函数的并存入数组next[]中。
char s[20]="adjfskjfskdjsfkglsi";
char t[5]="skdj";
int next[5];
int pos=0;
void main()
{
    int n;
    get_next(t,next);
    n=index_KMP(s,t,pos);
    if(n!=0)
        printf("\n模式串 t 在主串 s 中第 %d 个位置之后。\n\n",n);
    else
        printf("\n主串中不存在与模式串相匹配的子串!\n\n");
}
int index_KMP(char *s,char *t,int pos)
//利用模式串的T的NEXT函数求t在主串s中的第pos个位置之后的位置的KMP算法，（t非空，1<=pos<=Strlength(s)）.
{
    int i=pos,j=1;
    while (i<=(int)strlen(s)&&j<=(int)strlen(t))
    {
        if (j==0  ||  s[i]==t[j-1]) //继续进行后续字符串的比较
        {
            i++;
            j++;
        }
        else j=next[j]; //模式串向右移动
    }
    if (j>(int)strlen(t)) //匹配成功
        return i-strlen(t)+1;
    else //匹配不成功
        return 0;
}
void get_next(char *t,int *next)
//求模式串t的next函数的并存入数组next[]中。
{
    int i=1,j=0;
    next[0]=next[1]=0;
    while (i<(int)strlen(t))
    {
        if (j==0 || t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

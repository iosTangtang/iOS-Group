//算法:求最后一个单词的长度，单词包括各种符号！
//代码:
#include<stdio.h>
#include<string.h>
#define M 200
int main (void)
{
    int i,j,len;
    char string[M];
    gets(string);
    len=strlen(string);
    if (len==0)
    {
        return 0;
    }
    if (len>128)
    {
        return -1;
    }
    i=j=len-1;
    while (string[i]==' ' && i>=0)
    {
        i--;
        j--;
    }
    while (string[i]!=' ' && i>=0)
    {
        i--;
    }
    printf("%d\n",j-i);
    return 0;
}

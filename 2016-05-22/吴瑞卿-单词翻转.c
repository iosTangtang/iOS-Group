//单词翻转
//
//题目描述 Description
//给出一个英语句子，希望你把句子里的单词顺序都翻转过来
//输入描述 Input Description
//输入包括一个英语句子。
//输出描述 Output Description
//按单词的顺序把单词倒序输出
//样例输入 Sample Input
//I love you
//样例输出 Sample Output
//you love I
//
//思路：分别用两个指针指向数组的头和尾，先交换单词，再交换句子。

#include <stdio.h>
#include <string.h>
#define N 100
void Reverseword(char*x,char*y)
{
    char t=*x;
    while(x<y)
    {
        *x++=*y;
        *y--=t;
        t=*x;
    }
}
int main()
{
    char a[N],*p=a,*q=a;
    gets(a);
    while(*q!='\0')
    {
        if(*q==' ')
        {
            Reverseword(p,q-1);
            q++;
            p=q;
        }
        else q++;
    }
    Reverseword(p,q-1);
    p=a;
    Reverseword(p,q-1);
    puts(a);
    return 0;
}



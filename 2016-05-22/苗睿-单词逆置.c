//将一个英文句子的前后单词逆置

#include <stdio.h>
int main()
{
    char str[81],*p1,*p2,*p,ch;
    printf("input a english sentence:\n ");
    gets(str);
    p1 = str;
    p2 = str;
    while(*p2)
        p2 ++ ;
    p2 -- ;
    while(p1 < p2)
    {
        ch = *p1;
        *p1++ = *p2;
        *p2-- = ch;
    }
    p = str;
    while(*p)
    {
        p1 = p;
        while(*p1 == ' ')
            p1 ++ ;
        p2 = p1;
        while(*p2 && *p2 != ' ')
            p2 ++ ;
        p = p2;
        p2 -- ;
        while(p1 < p2)
        {
            ch = *p1;
            *p1 ++ = *p2;
            *p2 -- = ch;
        }
    }
    printf("turn english sentence:\n");
    puts(str);
    return 0;
}

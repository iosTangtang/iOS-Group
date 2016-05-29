#include"studio.h"
void reverse()
{
    char c;
    scanf("%c",&c);
    if(c!='\n')
    {
        reverse();
        printf("%c",c);
    }
}
main()
{
    reverse();
}
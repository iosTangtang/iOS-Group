#include<stdio.h>
char * strstring(char *ParentString, char *SubString)
{   char *pSubString, *pPareString;
    for(char *pTmp=ParentString; *pTmp; pTmp++)
    {
        pSubString = SubString;
        pPareString = pTmp;
        while(*pSubString == *pPareString && *pSubString != '\0')
        {
            pSubString++;
            pPareString++;
        }
        if(*pSubString == '\0')
        {
            return pTmp;
        }
        return NULL ；
    }
}

int main(void)
{
    char *ParentString = "happy birthday to you!";
    char *SubString = "birthday";
    printf("%s",strstring(ParentString, SubString));
}

//求连续递增最大数字子串
//（如“ads3sl456789DF3456ld345AA”中的“456789”）

#include <stdio.h>
int  GetSubString(char  *strSource,  char  *strResult)  {
    int  iTmp=0,  iHead=0,  iMax=0;
    for(int  Index=0,  iLen=0;  strSource[Index];  Index++)  {
        if(strSource[Index]  >=  '0'  &&  strSource[Index]  <=  '9'  &&
           strSource[Index-1]  >  '0'  &&  strSource[Index]  ==  strSource[Index-1]+1)  {
            iLen++;
        }
        else  {
            if(iLen  >  iMax)  {
                iMax  =  iLen;    iHead  =  iTmp;
            }
            if(strSource[Index]  >=  '0'  &&  strSource[Index]  <=  '9')
            {
                iTmp  =  Index;
                iLen  =  1;
            }
        }
    }
    for(iTmp=0  ;  iTmp  <  iMax;  iTmp++)
        strResult[iTmp]  =  strSource[iHead++];
    strResult[iTmp]='\0';
    return  iMax;
}


int  main()  {
    char  strSource[]="ads3sl456789DF3456ld345AA",  char  strResult[sizeof(strSource)];
    printf("Len=%d,  strResult=%s  \nstrSource=%s\n",
           GetSubString(strSource,  strResult),  strResult,  strSource);
    return  0；
}
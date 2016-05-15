//从键盘输入一组数，输出里面不重复的子序列，例如
//输入
//5
//1 8 8 8 1
//输出
//1 8

#include<stdio.h>
int main()
{
    int m,a[m];
    int i=0,j,k;
    scanf("%d",&m);
    for(i=0; i<m; i++)  scanf("%d",&a[i]);
    i=0;
    while(i<m)
    {
        for(j=i+1; j<m; j++)
        {
            if(a[i]==a[j])
            {
                a[j]=a[j-1];
            }
        }
        for(j=i+1; j<m; j++)
        {
            if(a[i]==a[j])
            {
                i++;
            }
            else
                break;
        }
        printf("%d ",a[i]);
        i++;
        
    } 
}

//算法的优化
//#include<stdio.h>
//int main()
//{
//    int i,j,k=0;
//    int flag,m;
//    scanf("%d",&m);
//    int a[m],*b=a;
//    for(i=0;i<m;i++)
//        scanf("%d",&a[i]);
//    
//    for(i=0;i<m;i++)
//    {     flag=0;
//        for(j=i-1;j>=0;j--)
//        {
//            if(a[i]==a[j])
//                flag=1;
//        }
//        if(flag==0)
//        {
//            *(b+k)=a[i];
//            k++;
//        }
//    }
//    for(i=0;i<k;i++)
//        printf("%d ",*(b+i));
//    return 0;
//}

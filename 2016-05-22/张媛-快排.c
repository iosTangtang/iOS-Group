#include<stdio.h>
void sort(int *a,int left,int right)
{ if(left>=right)
{  return;  }
    int i=left;
    int j=right;
    int k=a[i];
    while(i<j)
    { while((a[j]>=k)&&(i<j))
    { j--; }
        a[i]=a[j];
        while((a[i]<=k)&&(i<j))
        { i++; }
        a[j]=a[i];
    }
    a[i]=k;
    sort(a,left,i-1);
    sort(a,i+1,right);
}

}
void main()
{ int i,a[5];
    printf("请输入五个数:\n");
    for(i=0;i<5;i++) scanf("%d",&a[i]);
    sort(a,0,4);
    for(i=0;i<5;i++) printf("%d",a[i]);
    printf("\n");
}

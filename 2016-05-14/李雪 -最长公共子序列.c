
//2:最长公共子序列

#include<stdio.h>

int main(){

    int data[100];
    int i,j;
    int Max[100];
    int n,t,k;

    printf("请输入n个数");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){

        scanf("%d",&data[i]);
    }

    for( i=0;i<100;i++){
        Max[i]=1; //给每一个序列点作为右端时的最大序列长度为1
    }
    
    for( i=1;i<n;i++){
        t=1;
        
        for( j=0;j<i;j++){//与其前面的每一个进行比较
            if(data[i]>data[j]){//如果数据比前面的某一个的值大
                if(Max[i]+Max[j]>t){//找出该点的最大子序列长度
                    t=Max[i]+Max[j];
                }

            }
        }
        Max[i]=t;
 
    }
    
    t=Max[0];
    
    for(i=1;i<n;i++){
        if(Max[i]>t){
            t=Max[i];
        }
    }
    printf("最长单调递增子序列的长度为：%d",t);
    return 0;
}
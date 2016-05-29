//算法 ：会场安排
#include<stdio.h>

typedef struct{
    
    int tag;
    
    int time;
    
}array;

int main(){
    
    int i,j;
    
    int n;
    
    int count = 0;
    
    int b[100];
    
    array   temp;
    
    array  a[100] ;
    
    int len ;
    
    int max;
    
    
    
    
    
    printf("请输入活动个数");
    
    scanf("%d",&n);
    
    len = 2*n;
    
    for(i=0;i<len;i++)
        
    {
        
        scanf("%d",&a[i].time);
        
        a[i].tag = i%2;//设置tag标记，start:0  end:1
        
    }
    
    //排序
    
    for(i=0;i<len-1;i++)
        
        for(j=0;j<len-i-1;j++)
            
        {
            
            if(a[j].time>a[j+1].time)
                
            {
                
                temp = a[j];
                
                a[j] = a[j+1];
                
                a[j+1] = temp;
                
            }
            
            
            
            //printf(" a[j]:  %d   ,a[j+1]:  %d, temp  : %d\n",a[j],a[j+1],temp);
            
        }
    
    for(i=0; i<len;i++){
        
        if(a[i].tag == 0)
            
            count+=1;
        
        
        
        else
            
            count-=1;
        
        b[i]= count;
        
        printf("%d\n",count);
        
        
        
    }
    
    //求最大值
    
    max = b[i];
    
    for(i = 1;i <len ;i++)
        
    {
        
        if(b[i]>max)
            
            max = b[i];
        
    }
    
    printf("max  是： %d",max);
    
    return 0;
    
}

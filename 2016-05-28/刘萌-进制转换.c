//算法：进制转换：
#include <iostream>
#include <math.h>
using namespace std;
typedef struct
{
    int data[100];
    int rear,front;
}LQueue;
LQueue * initQueue(LQueue *q)  //初始化队列
{
    q=(LQueue *)malloc(sizeof(LQueue));
    q->front=0;
    q->rear=0;
    return q;
}
void InQueue(LQueue *q,int x)  //入队
{
    if(q->rear!=100)
    {
        q->data[q->rear]=x;
        q->rear++;
    }
}
void DeleteQueue(LQueue *q,int &x)  //出队
{
    if(q->front!=100)
    {
        x=q->data[q->front];
        q->front++;
    }
}
int IsEmptyQueue(LQueue *q)    //判空队
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
int main ()
{
    int a;
    int e;
    int i;
    LQueue *s;
    s=initQueue(s);
    double sum=0;
    cout<<"请输入二进制小数，输入回车结束"<<endl;
    getchar();//输入0
    getchar();//输入小数点
    //小数点以后开始入队
    while((e=getchar())!='\n')
    {
        a=e-48;
        InQueue(s,a);//入队
    }
    i=1;
    while(!IsEmptyQueue(s))
    {
        DeleteQueue(s,a);//出对
        sum+=a*pow(2,-i);//sum=sum加上a*2的-1次方
        i++;
    }
    cout<<"对应小数是："<<sum<<endl;
    return 0;
}

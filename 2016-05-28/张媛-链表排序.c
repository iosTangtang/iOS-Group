#include <stdio.h>
#include<stdlib.h>
struct student
{   int num;
    struct student *next;
};
int icount;
struct student *create()
{    struct student *phead=NULL;
    struct student *pend,*pnew;
    icount=0;
    pend=pnew=(struct student *)malloc(sizeof(struct student))
    printf("please input anumbert:\n");
    scanf("%d",&pnew->num);
    while(pnew->num!=0){
        icount++;
        if(icount==1)
        {      pnew->next=NULL;
            pend=pnew;
            phead=pnew;
        }
        else
        {       pnew->next=NULL;
            pend->next=pnew;
            pend=pnew;
        }
        pnew=(struct student *)malloc(sizeof(struct student));
        scanf("%d",&pnew->num);
    }
    free(pnew);
    return phead;
}
void sort(struct student *phead)
{
    int ptemp;
    struct student *p,*q;
    for(p=phead; p!=NULL; p=p->next)
    {
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(p->num>q->num)
            {
                ptemp=p->num;
                p->num=q->num;
                q->num=ptemp;
                
            }
        }
    }
    
}
void sort1(struct student *phead)
{
    struct student *p,*q;
    int temp;
    for(p=phead; p!=NULL; p=p->next)
        for(q=p->next; q!=NULL; q=q->next)
            if(p->num<q->num)
            {
                temp=p->num;
                p->num=q->num;
                q->num=temp;
            }
}
void print(struct student *phead)
{
    struct student *ptemp;
    int iindex=1;
    ptemp=phead;
    while(ptemp!=NULL){
        printf("第%d个数是:\n",iindex);
        printf("%d\n",ptemp->num);
        ptemp=ptemp->next;
        iindex++;
    }
}
int main()
{
    struct student *phead;
    phead=create();
    sort(phead);
    print(phead);
    sort1(phead);
    print(phead);
} 


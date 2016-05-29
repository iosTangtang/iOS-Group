//一堆猴子都有编号，编号是1，2，3 ...n，这群猴子（n个）按照1-n的顺序围坐一圈，从第1开始数，每数到第m个，该猴子就要离开此圈，这样依次下来，直到圈中只剩下最后一只猴子，则该猴子为大王。
//
//思路：创建一个链表，每个节点存编号，并将链表的尾连头，每当数到m时就讲该节点删除，最后剩下一个输出编号就好。
#include <stdio.h>
typedef struct Monkey{
    int number;
    struct Monkey *next;
}monkey;
int main()
{
    int i,m,n;
    monkey *pHead,*s,*stu,*p,*pre,*temp;
    scanf("%d%d",&n,&m);
    pHead=(monkey*)malloc(sizeof(monkey));
    pHead->next=NULL;
    s=pHead;
    for(i=1;i<=n;i++)
    {
        stu=(monkey*)malloc(sizeof(monkey));
        stu->number=i;
        s->next=stu;
        s=stu;
    }
    s->next=pHead->next;
    p=pHead;
    while(p->next!=pre)
    {
        for(i=0;i<m;i++)
        {
            pre=p;
            p=p->next;
        }
        pre->next=p->next;
        free(p);
        p=pre;
    }
    printf("%d",pre->number);
    return 0;
}


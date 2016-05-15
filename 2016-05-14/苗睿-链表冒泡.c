//方法：不定义临时变量来交换链表数据域的内容，而是直接交换链表的指向，最后返回头指针

void *sort (struct student *phead)  //带头结点的链表
{
    struct student *p1,*p2,*p3,*p;
    int i ;
    for (i = 0 ; i < icount ; i++)    //icount 表示结点的个数，定义的时候定义为全局变量//故此处可以直接用
    {
		      p=phead;
		      p1=phead->next;
		      p2=p1->next;
        while(p1->next!=NULL)
		      {
                  if (p1->data > p2->data)
                  {
                      p->next=p2;
                      p1->next=p2->next;
                      p2->next=p;
                  }
                  //在交换完指针的指向后  p1 和 p2 的位置也随之改变，故需
                  //一个指针来交换 p1 和p2的位置
                  p3=p1;
                  p1=p2; 
                  p2=p3;
              }
    }
}


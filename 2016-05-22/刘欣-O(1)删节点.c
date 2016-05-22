//给定一个单链表的头指针和一个指定节点的指针，在O(1)时间删除该节点;
void DeleteNode(NodeL* head,NodeL* delNode)
{
    if (!head || !delNode)
    {
        return;
    }
    
    if (delNode->next!=NULL)//删除中间节点
    {
        NodeL* next=delNode->next;
        delNode->next=next->next;
        delNode->value=next->value;
        delete next;
        next=NULL;
    }else if (head==delNode)//删除头结点
    {
        delete delNode;
        delNode=NULL;
        *head=NULL;
    }else//删除尾节点，考虑到delNode不在head所在的链表上的情况
    {
        NodeL* tmpNode=head;
        while (tmpNode && tmpNode->next!=delNode)
        {
            tmpNode=tmpNode->next;
        }
        if (tmpNode!=NULL)
        {
            delete delNode;
            delNode=NULL;
            tmpNode->next=NULL;
        }
    }
}

void DeleteNodeTest()
{
    int nodeCount=10;
    for (int K=0;K<nodeCount;K++)
    {
        NodeL* head=NULL;
        NodeL* cur=NULL;
        NodeL* delNode=NULL;
        for (int i=0;i<nodeCount;i++)
        {
            NodeL* tmpNode=new NodeL(i);
            if (i==0)
            {
                cur=head=tmpNode;
            }else{
                cur->next=tmpNode;
                cur=tmpNode;
            }
            if (i==K)
            {
                delNode=tmpNode;
            }
        }
        DeleteNode(head,delNode) ;
    }
}
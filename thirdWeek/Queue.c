#include <stdio.h>
#include <stdlib.h>
//typedef int type;
typedef struct Node* linkList;


 struct Node                                         // 链表节点
 {
    void *data;                                 // 存储的数据指针
    linkList next;                              // 指向下一个链表节点
    void (*linkListOutput)(linkList);           // 输出链表中数据到控制台操作的函数指针
 };
 typedef struct Queue
{
    linkList head;
    linkList tail;
}QQ;

 linkList initialLinklist();                         // 开辟新的节点空间
 void EnQueue(QQ *q, void *data,int a);              // 入队
 void linkListOutput(linkList h);                    // 未指定输出类型时的默认输出函数
 void stringLinkListOutput(linkList h);              // 输出字符串类型链表中数据到控制台
 void intLinkListOutput(linkList h); 		         // 输出整型链表中数据到控制台
 void doubleLinkListOutput(linkList h); 		     // 输出浮点型链表中数据到控制台
 void charLinkListOutput(linkList h); 		         // 输出字符型链表中数据到控制台
 void DestroyQueue(QQ *q);                           // 销毁队列
 void DeQueue(QQ *q);                                // 出队
 void GetHeadQueue(QQ *q);                           // 返回队头元素
 void IsEmptyQueue(QQ *q);                           // 判断队列是否为空
 void output(QQ *q);                                 // 遍历队列



linkList initialLinklist(void *data,int a) //开辟新的节点空间
 {
    linkList link = (linkList)malloc(sizeof(struct Node));
    link->data = data;
    link->next = NULL;
    switch(a)//存储数据类型
    {
    case 1: link->linkListOutput = intLinkListOutput;break;
    case 2: link->linkListOutput = charLinkListOutput;break;
    case 3: link->linkListOutput = doubleLinkListOutput;break;
    case 4: link->linkListOutput = stringLinkListOutput;break;
    }

    return link;
 }

void EnQueue(QQ *q, void *data,int a) //在队尾插入节点
 {
    if((q->head==NULL)&&(q->tail==NULL))    //当队列的对头和队尾都为空时
    {
        linkList link = initialLinklist(data,a);
        q->head=link;
        q->tail=link;
    }
    else    //当队列的对头和队尾不都为空时
    {
        linkList link = initialLinklist(data,a);
        q->tail->next=link;
        q->tail=link;
    }
 }

void linkListOutput(linkList h)     //空的输出函数
 {
  printf("You should point which output function is wanted!\n");
 }

void stringLinkListOutput(linkList h)    //字符串输出函数
 {
    printf("%s\t", (char*)(h->data));
    printf("\n");
 }

void intLinkListOutput(linkList h)     //整数型输出函数
 {
    printf("%d\t", *(int*)(h->data));
    printf("\n");
 }

void doubleLinkListOutput(linkList h)   //浮点型输出函数
 {
    printf("%f\t", *(double*)(h->data));
    printf("\n");
 }

void charLinkListOutput(linkList h)     // 字符型输出函数
 {
    printf("%c\t", *(char*)(h->data));
    printf("\n");
 }

void DestroyQueue(QQ *q)    // 销毁队列
{
    while(q->head)  //当队头指针不为NULL时
    {
        DeQueue(q); //出队
    }
    printf("队列一成功销毁！\n");
}

void DeQueue(QQ *q) // 出队
{
    if(q->head==NULL)
    {
        printf("队列已空！\n");
        return;
    }
    linkList p;
    p=q->head;
    printf("出队元素：");
    p->linkListOutput(p);   //输出队头元素
    if(q->head->next!=NULL)
    {
        q->head=q->head->next;
        free(p);
    }
    else
    {
        q->head=NULL;
        q->tail=NULL;
        free(p);
    }
}

void GetHeadQueue(QQ *q)    // 返回队头元素
{
    if(q->head==NULL)
    {
        printf("队列已空！\n");
        return;
    }
    q->head->linkListOutput(q->head);
}

void IsEmptyQueue(QQ *q)    // 判断队列是否为空
{
    if(q->head==NULL) printf("目前队列为空！\n");
    else printf("队列不为空！\n");
}

void output(QQ *q)
{
    linkList p;
    int i=0;    //  用于计数
    p=q->head;
    /*pt=q->tail;
    pt->linkListOutput(pt);*/
    while(p)
    {
        printf("第%d个元素\t\t",i++);
        p->linkListOutput(p);
        p=p->next;
    }

}

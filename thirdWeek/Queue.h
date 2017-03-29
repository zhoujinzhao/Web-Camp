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


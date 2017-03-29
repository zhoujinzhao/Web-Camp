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


int main()
{
    QQ *Q;
    Q=(QQ*)malloc(sizeof(QQ));
    Q->head=NULL;Q->tail=NULL;
    int choice;
    int idata; double ddata; char cdata,sdata[20];
    while(1)
    {
        printf("\t\t请选择要进行什么操作(输入1-7)：\n");
        printf("\t\t1、输入一个整数型数据\n");
        printf("\t\t2、输入一个字符型数据\n");
        printf("\t\t3、输入一个浮点型数据\n");
        printf("\t\t4、输入一个字符串数据\n");
        printf("\t\t5、遍历队列\n");
        printf("\t\t6、返回队头\n");
        printf("\t\t7、队列是否为空\n");
        printf("\t\t8、出队\n");
        printf("\t\t9、销毁队列\n");
        printf("\t\t10、退出\n");
        scanf("%d",&choice);        //输入要选择的操作
        if(choice<0||choice>10)
        {
            printf("输入错误！请重新选择！\n");continue;
        }
        switch(choice)
        {
        case 1: printf("请输入一个整数型数据：");
                scanf("%d",&idata);
                EnQueue(Q,&idata,choice);break;
        case 2: printf("请输入一个字符型数据：");
                getchar();cdata=getchar();
                EnQueue(Q,&cdata,choice);break;
        case 3: printf("请输入一个浮点型数据：");
                scanf("%lf",&ddata);
                EnQueue(Q,&ddata,choice);break;
        case 4: printf("请输入一个字符串数据：");
                scanf("%s",sdata);
                EnQueue(Q,sdata,choice);break;
        case 5: output(Q);break;
        case 6: GetHeadQueue(Q);break;
        case 7: IsEmptyQueue(Q);break;
        case 8: DeQueue(Q);break;
        case 9: DestroyQueue(Q);break;
        case 10: return 0;
        }
    }
    return 0;
}

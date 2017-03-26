#include <stdio.h>
#include <stdlib.h>
/**  * 双向链表操作  */
typedef struct TNode {
    int data;
    struct TNode *next;
    struct TNode *pre;
}TNode, *ptr_TNode;
typedef enum Status {
      SUCCESS,ERROR
}Status;
 //生成双向链表
ptr_TNode create(int *arr, int n);
 ptr_TNode tails(ptr_TNode head);
Status delete_T(ptr_TNode *head, int index, int *data);
Status insert_T(ptr_TNode *head, ptr_TNode node, int index);
void print_next(ptr_TNode head);
void print_pre(ptr_TNode tail);
void destroy(ptr_TNode head);
int main()
{
    int b[8]={1,2,3,4,5,6,7,8},index,data,choice;//index为位置，
    ptr_TNode head,tail,node;
    head=create(b,8);                       //生成双向链表
    tail=tails(head);                       //读取尾节点
    print_next(head);                       //顺序输出
    print_pre(tail);                        //逆序输出
    while(1)
    {
        printf("\t\t请选择要进行什么操作(输入1-3)：\n");
        printf("\t\t1、插入节点\n");
        printf("\t\t2、删除节点\n");
        printf("\t\t3、退出\n");
        scanf("%d",&choice);        //输入要选择的操作
        if(choice<0||choice>3)
        {
            printf("输入错误！\t");continue;
        }
        switch(choice)
        {
        case 1: printf("请输入要插入的位置：");
                scanf("%d",&index);             //index为要插入的位置
                if(insert_T(&head,node,index)==1)   printf("未成功插入！\n");//插入函数
                else print_next(head);break;
        case 2: printf("请输入要删除的位置：\n");       //输入删除位置
                scanf("%d",&index);
                if(delete_T(&head,index,&data)==1) printf("没有该节点\n");//data存储删除数据，ed接手删除函数返回结果
                else printf("删除了%d\n",data);
                print_next(head);break;
        case 3: destroy(head);return 0;       //销毁链表//结束程序
        }
    }
    return 0;
}

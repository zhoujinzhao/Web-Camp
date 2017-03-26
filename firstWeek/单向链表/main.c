#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node, *ptr_Node;

typedef enum Status {
    SUCCESS, ERROR
}Status;
ptr_Node create(int *arr, int n);
void destroy(ptr_Node head);
Status insert(ptr_Node *head, ptr_Node node, int index);
Status delete(ptr_Node *head, int index, int *data);
ptr_Node search(ptr_Node head, int data);
 Status edit(ptr_Node head, int index, int *data);
void print(ptr_Node head);
Status sort(ptr_Node *head);
int main()
{
    int a[8]={8,7,6,5,4,3,2,1};     //数组
    ptr_Node head,node;             //node为插入的新节点
    int index,temp,choice;
    head=create(a,8);               //转化数组为链表
    print(head);                    //输出当前链表
    sort(&head);
    print(head);
    while(1)
    {
        printf("\t\t请选择要进行什么操作(输入1-5)：\n");
        printf("\t\t1、插入节点\n");
        printf("\t\t2、删除节点\n");
        printf("\t\t3、查找节点\n");
        printf("\t\t4、修改节点\n");
        printf("\t\t5、销毁链表\n");
        printf("\t\t6、退出\n");
        scanf("%d",&choice);        //输入要选择的操作
        if(choice<0||choice>6)
        {
            printf("输入错误！\t");continue;
        }
        switch(choice)
        {
        case 1: printf("请输入要插入的位置：");
                scanf("%d",&index);         //index为要插入的位置
                if(insert(&head,node,index)==1) printf("插入失败！\n");    //插入函数
                print(head);break;
        case 2: printf("请输入要删除的节点的位置：");
                scanf("%d",&index);         //index为要删除的节点的前一个位置
                if(delete(&head,index,&temp)==1) print("删除失败!\n");   //删除函数
                else printf("删除了%d\n",temp);
                print(head);break;
        case 3: printf("请输入要查询的数据：");
                scanf("%d",&index);         //index为要查询的数据
                int ad=search(head,index);  //定义ad接收查询函数返回的结果
                if(ad==-1) printf("该数据不存在\n");
                else printf("该数据的位置为%d\n",ad);
                print(head);break;
        case 4: printf("请输入要修改的数据的位置：");
                scanf("%d",&index);         //index为要修改的数据的位置
                printf("请输入修改后的数据：");
                scanf("%d",&temp);          //temp为要改成的数据
                int ed=edit(head,index,&temp);//定义ed接收修改函数返回的结果
                if(ed==1) printf("修改错误！\n");
                else printf("%d已成功修改\n",temp);
                print(head);break;
        case 5: destroy(head);break;        //销毁链表
        case 6: return 0;                   //结束程序
        }
    }
    return 0;
}

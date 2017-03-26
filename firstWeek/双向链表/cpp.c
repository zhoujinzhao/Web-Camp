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
ptr_TNode create(int *arr, int n)
{
    if(arr==NULL) return NULL;  //若数组为空数组，返回NULL
    int i=0;
    ptr_TNode p,q,head;
    p=q=(ptr_TNode)malloc(sizeof(TNode));
    head=NULL;
    p->data=*arr;       //读取数组数据
    while(i<n)
    {
        if(i==0)
        {
            p->pre=NULL;//逆向链接的尾节点
            head=p;     //当i=0时读取到头指针
        }
        else
        {
            p->pre=q;   //逆向链接
            q->next=p;  //当i!=0时，构建链接
        }
        q=p;i++;
        p=(ptr_TNode)malloc(sizeof(TNode));
        p->data=*(arr+i);   //读取下一元素
    }
    q->next=NULL;   //最后一位指针指向NULL
    return(head);   //返回头指针
}
 ptr_TNode tails(ptr_TNode head)//返回尾节点
 {
     ptr_TNode p;
     p=head;
     while(p->next!=NULL)
     {
         p=p->next;
     }
     return p;
 }
//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
Status delete_T(ptr_TNode *head, int index, int *data)
{
    if(head==NULL||*head==NULL||index<0) return ERROR;  //当头指针为NULL或index值不合理时
    ptr_TNode p,q;
    p=*head;
    if(index==0)    //删除第一个节点
    {
        *data=p->data;
        p=p->next;q=*head;*head=p;
        free(q);return SUCCESS;
    }
    int n=0;            //n表示节点位置
    while(p!=NULL)
    {
        if(n==index-1)    //找到指定位置后
        {   //删除操作
            *data=p->next->data;
            q=p->next;
            p->next=p->next->next;
            free(q);return SUCCESS; //释放空间并返回SUCCESS
        }
        n++;            //位置+1
        p=p->next;      //指向下一节点
    }
    return ERROR;
}
//双向链表,在第 index 位后面插入 node 结点 //插入成功返回 SUCCESS，失败返回 ERROR
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
    if(head==NULL||*head==NULL||index<0) return ERROR;  //头指针为NULL时和index值不合理时
    ptr_TNode p;
    node=(ptr_TNode)malloc(sizeof(TNode));//开辟新空间
    printf("请输入要插入的数据：");
    scanf("%d",&node->data);    //输入要插入的节点的数据
    p=*head;
    if(index==0)
    {
        node->next=*head;*head=node;//插入到第一个节点
        return SUCCESS;
    }
    int n=0;            //n表示节点位置
    while(p!=NULL)
    {
        if(n==index-1)    //找到位置后
        {   //插入操作
            node->next=p->next;
            p->next=node;
            return SUCCESS;
        }
        n++;            //位置+1
        p=p->next;      //指向下一节点
    }
    return ERROR;
}
//输出链表  顺序
void print_next(ptr_TNode head)//按顺序输出
{
    if(head==NULL) return;
    ptr_TNode p;
    p=head;
    int b=1;//表示第几个元素
    printf("链表当前元素如下：\n");
    while(p!=NULL)
    {
        printf("第%d位元素：%d\n",b++,p->data);//输出
        p=p->next;//指向下一节点
    }
}
//输出链表 逆序
void print_pre(ptr_TNode tail)//从尾节点开始输出（逆序）
{
    ptr_TNode q;
    q=tail;
    int b=0;
    printf("逆序输出如下：\n");
    while(q!=NULL)
    {
        printf("第%d个元素是%d\n",b++,q->data);
        q=q->pre;
    }
}

//销毁给定的链表
void destroy(ptr_TNode head)
{
    ptr_TNode p,q;
    p=head;
    while(p)
    {
        q=p->next;  //q指向下一指针
        free(p);    //释放p的空间
        p=q;        //试p指向q
    }
    head=NULL;      //让头指针指向BULL
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFREASIBLE -1
#define OVERFLOW -2
#define INCREMENT 10

typedef int Status;
typedef int ElemType;


typedef struct SqStack{
    ElemType *elem;
    int top;
    int size;
}SqStack;

int main()
{
    SqStack *Sq;
    Sq=(SqStack *)malloc(sizeof(SqStack));
    int SIZE,choice;ElemType e;
    while(1)
    {
        printf("\t\t请选择要进行什么操作(输入1-7)：\n");
        printf("\t\t1、建栈\n");
        printf("\t\t2、压栈\n");
        printf("\t\t3、出栈\n");
        printf("\t\t4、返回栈顶元素\n");
        printf("\t\t5、是否为空栈\n");
        printf("\t\t6、释放栈空间\n");
        printf("\t\t7、退出\n");
        scanf("%d",&choice);        //输入要选择的操作
        if(choice<0||choice>7)
        {
            printf("输入错误！\t");continue;
        }
        switch(choice)
        {
        case 1: printf("请输入栈的长度\n");
                scanf("%d",&SIZE);
                if(initStack(Sq,SIZE)==OVERFLOW) printf("内存已满!\n");    //建栈
                else printf("建栈成功！\n");break;
        case 2: printf("请输入要添加的元素【整型】:\n");
                scanf("%d",&e);
                if(push(Sq,e)==ERROR) printf("添加失败!\n");
                else printf("已成功添加元素%d！\n",e);break;
        case 3: if(pop(Sq,&e)==ERROR) printf("错误！\n");
                else printf("删除栈顶元素%d\n",e);break;
        case 4: if(getTop(Sq,&e)==ERROR) printf("错误！\n");
                else printf("栈顶元素为%d\n",e);break;
        case 5: if(isEmptyStack(Sq)) printf("是空栈！\n");
                else printf("不是空栈！\n");break;
        case 6: if(desttoyStack(Sq)==ERROR) printf("错误！\n");
                else printf("释放成功！\n");break;
        case 7:return 0;

        }
    }
    printf("请输入要添加的元素:\n");
    scanf("%d",&e);
    if(push(Sq,e)==ERROR) printf("添加失败!\n");
    else printf("已成功添加元素%d！\n",e);
    return 0;
}

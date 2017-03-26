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


typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr 	 top;	  //栈顶指针
	int		 count;  //栈中元素个数
}LinkStack;

int main()
{
    LinkStack *Sq;
    char s;
    Sq=(LinkStack *)malloc(sizeof(LinkStack));//开辟新空间
    int choice;char e;
    while(1)
    {
        printf("\t\t请选择要进行什么操作(输入1-5)：\n");
        printf("\t\t1、建栈\n");
        printf("\t\t2、压栈\n");
        printf("\t\t3、出栈\n");
        printf("\t\t4、返回栈顶元素\n");
        printf("\t\t5、是否为空栈\n");
        printf("\t\t6、释放栈空间\n");
        printf("\t\t7、输出所有栈内元素\n");
        printf("\t\t8、返回栈的长度\n");
        printf("\t\t9、退出\n");
        scanf("%d",&choice);        //输入要选择的操作
        if(choice<0||choice>9)
        {
            printf("输入错误！\n");continue;
        }
        switch(choice)
        {
        case 1: if(initStack(Sq)==OVERFLOW) printf("内存已满!\n");    //建栈
                else printf("建栈成功！\n");break;
        case 2: printf("请输入要添加的元素【整型】:\n");
                getchar();
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
        case 7: if(print(Sq)==ERROR) printf("错误！\n");break;
        case 8: printf("栈目前的长度为%d\n",Sq->count);break;
        case 9: return 0;

        }
    }
    return 0;
}

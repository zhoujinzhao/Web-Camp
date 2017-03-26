#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFREASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;
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
    int choice;
    while(1)
    {
        printf("请输入选项(1为四则运算，2为退出)：");
        scanf("%d",&choice);getchar();
        switch(choice)
        {
        case 1:f();break;
        case 2:return 0;
        }
    }
    return 0;
}

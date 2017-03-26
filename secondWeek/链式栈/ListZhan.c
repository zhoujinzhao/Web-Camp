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


//建立一个空栈
Status initStack(LinkStack *S)
{
    LinkStackPtr p;
    p=(LinkStackPtr)malloc(sizeof(StackNode));
    if(p==NULL)    return OVERFLOW;
    S->top=p;
    p->next=NULL;
    S->count=0;
    return OK;

}

//压栈
Status push(LinkStack *S,ElemType e)
{
    if(S==NULL||S->top==NULL)
        return ERROR;
    LinkStackPtr p;
    p=(LinkStackPtr)malloc(sizeof(S));
    if(!p) return ERROR;
    S->top->data=e;
    p->next=S->top;
    S->top=p;
    S->count++;
    return OK;
}

//出栈
Status pop(LinkStack *S, ElemType *e)
{
    if(S->top->next==NULL||S->top==NULL||S==NULL)
        return ERROR;
    LinkStackPtr p;
    p=S->top;
    S->top=S->top->next;
    *e=S->top->data;
    free(p);
    S->count--;
    return OK;

}

//若栈不空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR
Status getTop(LinkStack *S, ElemType *e)
{
    if(S==NULL||S->top==NULL||S->top->next==NULL)
        return ERROR;
    LinkStackPtr p;
    p=S->top->next;
    *e=p->data;
    return OK;
}

//栈为空返回TRUE;否则返回FALSE
Status isEmptyStack(LinkStack *S)
{
    if(S->top->next==NULL) return TRUE;
    return FALSE;
}

//若栈不为空，则释放栈空间；否则返回ERROR
Status desttoyStack(LinkStack *S)
{
    if(S==NULL) return ERROR;
    LinkStackPtr p;
    p=S->top;
    while(p)
    {
        S->top=p->next;
        free(p);
        p=S->top;
    }
    return OK;
}

//从栈顶开始依次输出
Status print(LinkStack *S)
{
    LinkStackPtr p;
    if(S->top->next==NULL||S->top==NULL||S==NULL) return ERROR;
    p=S->top->next;
    while(p)
    {
        printf("\t|\t%d\n",p->data);
        printf("\t-----------------\n");
        p=p->next;
    }
    return OK;
}

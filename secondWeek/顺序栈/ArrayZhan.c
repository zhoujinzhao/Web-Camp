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

//建立一个空栈
Status initStack(SqStack *S,int size)
{
    S->elem = (ElemType *)malloc(size * sizeof(ElemType));
    if(NULL == S->elem)
        return OVERFLOW;
    S->top = -1;
    S->size = size;
    return OK;
}

//压栈
Status push(SqStack *S,ElemType e)
{
    if(NULL == S || S->top>=S->size -1)  //栈满
                return ERROR;
    S->top++;
    S->elem[S->top] = e;
    return OK;
}

//出栈
Status pop(SqStack *S, ElemType *e)
{
    if(NULL == S || S->top == -1)
        return ERROR;
    *e = S->elem[S->top];
    S->top--;
    return OK;
}

//若栈不空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR
Status getTop(SqStack *S, ElemType *e)
{
    if(NULL == S || S->top == -1)
            return ERROR;
    else
            {*e = S->elem[S->top];}
    return OK;
}

//栈为空返回TRUE;否则返回FALSE
Status isEmptyStack(SqStack *S)
{
    return (-1 == S->top? TRUE : FALSE);
}

//若栈不为空，则释放栈空间；否则返回ERROR
Status desttoyStack(SqStack *S)
{
    if(NULL == S)
        return ERROR;
    free(S->elem);
    return OK;
}

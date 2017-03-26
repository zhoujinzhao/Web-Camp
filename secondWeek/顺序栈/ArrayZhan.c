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

//����һ����ջ
Status initStack(SqStack *S,int size)
{
    S->elem = (ElemType *)malloc(size * sizeof(ElemType));
    if(NULL == S->elem)
        return OVERFLOW;
    S->top = -1;
    S->size = size;
    return OK;
}

//ѹջ
Status push(SqStack *S,ElemType e)
{
    if(NULL == S || S->top>=S->size -1)  //ջ��
                return ERROR;
    S->top++;
    S->elem[S->top] = e;
    return OK;
}

//��ջ
Status pop(SqStack *S, ElemType *e)
{
    if(NULL == S || S->top == -1)
        return ERROR;
    *e = S->elem[S->top];
    S->top--;
    return OK;
}

//��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status getTop(SqStack *S, ElemType *e)
{
    if(NULL == S || S->top == -1)
            return ERROR;
    else
            {*e = S->elem[S->top];}
    return OK;
}

//ջΪ�շ���TRUE;���򷵻�FALSE
Status isEmptyStack(SqStack *S)
{
    return (-1 == S->top? TRUE : FALSE);
}

//��ջ��Ϊ�գ����ͷ�ջ�ռ䣻���򷵻�ERROR
Status desttoyStack(SqStack *S)
{
    if(NULL == S)
        return ERROR;
    free(S->elem);
    return OK;
}

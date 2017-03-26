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
	LinkStackPtr 	 top;	  //ջ��ָ��
	int		 count;  //ջ��Ԫ�ظ���
}LinkStack;


//����һ����ջ
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

//ѹջ
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

//��ջ
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

//��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status getTop(LinkStack *S, ElemType *e)
{
    if(S==NULL||S->top==NULL||S->top->next==NULL)
        return ERROR;
    LinkStackPtr p;
    p=S->top->next;
    *e=p->data;
    return OK;
}

//ջΪ�շ���TRUE;���򷵻�FALSE
Status isEmptyStack(LinkStack *S)
{
    if(S->top->next==NULL) return TRUE;
    return FALSE;
}

//��ջ��Ϊ�գ����ͷ�ջ�ռ䣻���򷵻�ERROR
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

//��ջ����ʼ�������
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

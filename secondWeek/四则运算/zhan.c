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
    //free(p);
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
        printf("%c",p->data);
        p=p->next;
    }
    return OK;
}

int SW(char a,int b , int c)//����
{
    switch(a)
    {
    case '+':return b+c;
    case '-':return b-c;
    case '*':return b*c;
    case '/':return b/c;
    /*case '(':return 0;
    case ')':return 0;*/
        default:return -1;
    }
}

void f()
{
    int    table[] = {0,0,2,1,0,1,0,2};//��ѯ��������ȼ���
    int i,ina[100],j=0,temp; //iΪѭ��������j��tempΪ�����±�
    LinkStack *Sc;
    char symbol;//��¼�׳��ķ���
    Sc=(LinkStack *)malloc(sizeof(LinkStack));
    initStack(Sc);
    int b=0;    // ��������ʮλ������ʱ��¼
    int priority=0; //��¼ջ��Ԫ�����ȼ�
    char s[100];
    printf("������׺���ʽ��ֻ֧����������������,��Ӣ��()����\n");gets(s);
    printf("��׺���ʽΪ��");
    for(i=0;s[i]!='\0';)    //����
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b=0;
            while(s[i]>='0'&&s[i]<='9')
            {
                b=b*10+(s[i]-'0');
                i++;
            }
            ina[j++]=b;printf("%d ",b);continue;
        }
        if(s[i]==41)    //����������ŵĻ�����ջ�������������ϵ��������������,Ȼ��continue
        {
            while(Sc->top->next->data!=40)
            {
                pop(Sc,&symbol);
                if(symbol!='(')
                {
                    printf("%c",symbol);
                    j--;temp=j-1;
                    ina[temp]=SW(symbol,ina[temp],ina[j]);//���м��㲢������洢������ina����
                    ina[j]=0;
                }
            }
            pop(Sc,&symbol);
            if(symbol!='(')
            {
                printf("%c",symbol);
                j--;temp=j-1;
                ina[temp]=SW(symbol,ina[temp],ina[j]);
                ina[j]=0;
            }
            if(Sc->top->next!=NULL)
            priority=table[Sc->top->next->data%10]; //ע���ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
            i++;continue;
        }

        if(s[i]==40)//����������ŵĻ���ֱ��ѹջ
        {
            push(Sc,s[i]);
            priority=table[Sc->top->next->data%10];
            i++;continue;
        }
        if(s[i]>=42&&s[i]<=47)//���ֻ����ͨ�����������ѹջ
        {
            //���ȱȽ�ջ��Ԫ�ص����ȼ��Ƿ����ջԪ�����ȼ�Ҫ��
            //����Ǵ��ڵĻ������ջ����Ԫ�����γ�ջ�󣬰Ѵ���ջ��Ԫ��ѹջ
            //��ָֹ��Ϊ��ʱ����
            if((priority>=table[s[i]%10])&&(Sc->top->next!=NULL))
            {
                while(priority>=table[s[i]%10]&&(Sc->top->next!=NULL)&&(Sc->top->next->data!=40))
                {
                    pop(Sc,&symbol);
                    if(symbol!='(')
                    {
                        printf("%c",symbol);
                        j--;temp=j-1;
                        ina[temp]=SW(symbol,ina[temp],ina[j]);
                        ina[j]=0;
                    }
                    if(Sc->top->next!=NULL)
                    priority=table[Sc->top->next->data%10];//ע��ÿ�εĳ�ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼���������Ƚ�
                }
                push(Sc,(int)s[i]);
                priority=table[Sc->top->next->data%10];//ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����
                i++;continue;
            }
            else
            {
                push(Sc,(int)s[i]);
                priority=table[Sc->top->next->data%10];
                i++;continue;
            }
        }
    }
    while(Sc->top->next!=NULL)
    {
        pop(Sc,&symbol);if(symbol!='(') printf("%c",symbol);
        j--;temp=j-1;
        ina[temp]=SW(symbol,ina[temp],ina[j]);
        ina[j]=0;
    }
    printf("\n���Ϊ%d\n",ina[0]);

}

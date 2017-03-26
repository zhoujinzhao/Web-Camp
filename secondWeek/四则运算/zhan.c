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
    //free(p);
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
        printf("%c",p->data);
        p=p->next;
    }
    return OK;
}

int SW(char a,int b , int c)//计算
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
    int    table[] = {0,0,2,1,0,1,0,2};//查询运算符优先级表
    int i,ina[100],j=0,temp; //i为循环变量，j和temp为数组下标
    LinkStack *Sc;
    char symbol;//记录抛出的符号
    Sc=(LinkStack *)malloc(sizeof(LinkStack));
    initStack(Sc);
    int b=0;    // 当数字是十位或以上时记录
    int priority=0; //记录栈顶元素优先级
    char s[100];
    printf("输入中缀表达式【只支持正整数四则运算,用英文()】：\n");gets(s);
    printf("后缀表达式为：");
    for(i=0;s[i]!='\0';)    //遍历
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
        if(s[i]==41)    //如果是右括号的话，将栈中在左括号以上的所有运算符弹出,然后continue
        {
            while(Sc->top->next->data!=40)
            {
                pop(Sc,&symbol);
                if(symbol!='(')
                {
                    printf("%c",symbol);
                    j--;temp=j-1;
                    ina[temp]=SW(symbol,ina[temp],ina[j]);//进行计算并将结果存储到数组ina里面
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
            priority=table[Sc->top->next->data%10]; //注意出栈后，须将新的栈顶元素的优先级记录下来
            i++;continue;
        }

        if(s[i]==40)//如果是左括号的话，直接压栈
        {
            push(Sc,s[i]);
            priority=table[Sc->top->next->data%10];
            i++;continue;
        }
        if(s[i]>=42&&s[i]<=47)//如果只是普通的运算符，则压栈
        {
            //首先比较栈顶元素的优先级是否比入栈元素优先级要大
            //如果是大于的话，则从栈顶将元素依次出栈后，把待入栈的元素压栈
            //防止指针为空时出错
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
                    priority=table[Sc->top->next->data%10];//注意每次的出栈后，须将新的栈顶元素的优先级记录下来用作比较
                }
                push(Sc,(int)s[i]);
                priority=table[Sc->top->next->data%10];//注意压栈后，须将新的栈顶元素的优先级记录下来
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
    printf("\n结果为%d\n",ina[0]);

}

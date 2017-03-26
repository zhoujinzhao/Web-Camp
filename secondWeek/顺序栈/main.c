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
        printf("\t\t��ѡ��Ҫ����ʲô����(����1-7)��\n");
        printf("\t\t1����ջ\n");
        printf("\t\t2��ѹջ\n");
        printf("\t\t3����ջ\n");
        printf("\t\t4������ջ��Ԫ��\n");
        printf("\t\t5���Ƿ�Ϊ��ջ\n");
        printf("\t\t6���ͷ�ջ�ռ�\n");
        printf("\t\t7���˳�\n");
        scanf("%d",&choice);        //����Ҫѡ��Ĳ���
        if(choice<0||choice>7)
        {
            printf("�������\t");continue;
        }
        switch(choice)
        {
        case 1: printf("������ջ�ĳ���\n");
                scanf("%d",&SIZE);
                if(initStack(Sq,SIZE)==OVERFLOW) printf("�ڴ�����!\n");    //��ջ
                else printf("��ջ�ɹ���\n");break;
        case 2: printf("������Ҫ��ӵ�Ԫ�ء����͡�:\n");
                scanf("%d",&e);
                if(push(Sq,e)==ERROR) printf("���ʧ��!\n");
                else printf("�ѳɹ����Ԫ��%d��\n",e);break;
        case 3: if(pop(Sq,&e)==ERROR) printf("����\n");
                else printf("ɾ��ջ��Ԫ��%d\n",e);break;
        case 4: if(getTop(Sq,&e)==ERROR) printf("����\n");
                else printf("ջ��Ԫ��Ϊ%d\n",e);break;
        case 5: if(isEmptyStack(Sq)) printf("�ǿ�ջ��\n");
                else printf("���ǿ�ջ��\n");break;
        case 6: if(desttoyStack(Sq)==ERROR) printf("����\n");
                else printf("�ͷųɹ���\n");break;
        case 7:return 0;

        }
    }
    printf("������Ҫ��ӵ�Ԫ��:\n");
    scanf("%d",&e);
    if(push(Sq,e)==ERROR) printf("���ʧ��!\n");
    else printf("�ѳɹ����Ԫ��%d��\n",e);
    return 0;
}

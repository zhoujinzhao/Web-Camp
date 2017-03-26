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

int main()
{
    LinkStack *Sq;
    char s;
    Sq=(LinkStack *)malloc(sizeof(LinkStack));//�����¿ռ�
    int choice;char e;
    while(1)
    {
        printf("\t\t��ѡ��Ҫ����ʲô����(����1-5)��\n");
        printf("\t\t1����ջ\n");
        printf("\t\t2��ѹջ\n");
        printf("\t\t3����ջ\n");
        printf("\t\t4������ջ��Ԫ��\n");
        printf("\t\t5���Ƿ�Ϊ��ջ\n");
        printf("\t\t6���ͷ�ջ�ռ�\n");
        printf("\t\t7���������ջ��Ԫ��\n");
        printf("\t\t8������ջ�ĳ���\n");
        printf("\t\t9���˳�\n");
        scanf("%d",&choice);        //����Ҫѡ��Ĳ���
        if(choice<0||choice>9)
        {
            printf("�������\n");continue;
        }
        switch(choice)
        {
        case 1: if(initStack(Sq)==OVERFLOW) printf("�ڴ�����!\n");    //��ջ
                else printf("��ջ�ɹ���\n");break;
        case 2: printf("������Ҫ��ӵ�Ԫ�ء����͡�:\n");
                getchar();
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
        case 7: if(print(Sq)==ERROR) printf("����\n");break;
        case 8: printf("ջĿǰ�ĳ���Ϊ%d\n",Sq->count);break;
        case 9: return 0;

        }
    }
    return 0;
}

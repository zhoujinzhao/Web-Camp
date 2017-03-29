#include <stdio.h>
#include <stdlib.h>
//typedef int type;
typedef struct Node* linkList;

 struct Node                                         // ����ڵ�
 {
    void *data;                                 // �洢������ָ��
    linkList next;                              // ָ����һ������ڵ�
    void (*linkListOutput)(linkList);           // ������������ݵ�����̨�����ĺ���ָ��
 };
 typedef struct Queue
{
    linkList head;
    linkList tail;
}QQ;
 linkList initialLinklist();                         // �����µĽڵ�ռ�
 void EnQueue(QQ *q, void *data,int a);              // ���
 void linkListOutput(linkList h);                    // δָ���������ʱ��Ĭ���������
 void stringLinkListOutput(linkList h);              // ����ַ����������������ݵ�����̨
 void intLinkListOutput(linkList h); 		         // ����������������ݵ�����̨
 void doubleLinkListOutput(linkList h); 		     // ������������������ݵ�����̨
 void charLinkListOutput(linkList h); 		         // ����ַ������������ݵ�����̨
 void DestroyQueue(QQ *q);                           // ���ٶ���
 void DeQueue(QQ *q);                                // ����
 void GetHeadQueue(QQ *q);                           // ���ض�ͷԪ��
 void IsEmptyQueue(QQ *q);                           // �ж϶����Ƿ�Ϊ��
 void output(QQ *q);                                 // ��������


int main()
{
    QQ *Q;
    Q=(QQ*)malloc(sizeof(QQ));
    Q->head=NULL;Q->tail=NULL;
    int choice;
    int idata; double ddata; char cdata,sdata[20];
    while(1)
    {
        printf("\t\t��ѡ��Ҫ����ʲô����(����1-7)��\n");
        printf("\t\t1������һ������������\n");
        printf("\t\t2������һ���ַ�������\n");
        printf("\t\t3������һ������������\n");
        printf("\t\t4������һ���ַ�������\n");
        printf("\t\t5����������\n");
        printf("\t\t6�����ض�ͷ\n");
        printf("\t\t7�������Ƿ�Ϊ��\n");
        printf("\t\t8������\n");
        printf("\t\t9�����ٶ���\n");
        printf("\t\t10���˳�\n");
        scanf("%d",&choice);        //����Ҫѡ��Ĳ���
        if(choice<0||choice>10)
        {
            printf("�������������ѡ��\n");continue;
        }
        switch(choice)
        {
        case 1: printf("������һ�����������ݣ�");
                scanf("%d",&idata);
                EnQueue(Q,&idata,choice);break;
        case 2: printf("������һ���ַ������ݣ�");
                getchar();cdata=getchar();
                EnQueue(Q,&cdata,choice);break;
        case 3: printf("������һ�����������ݣ�");
                scanf("%lf",&ddata);
                EnQueue(Q,&ddata,choice);break;
        case 4: printf("������һ���ַ������ݣ�");
                scanf("%s",sdata);
                EnQueue(Q,sdata,choice);break;
        case 5: output(Q);break;
        case 6: GetHeadQueue(Q);break;
        case 7: IsEmptyQueue(Q);break;
        case 8: DeQueue(Q);break;
        case 9: DestroyQueue(Q);break;
        case 10: return 0;
        }
    }
    return 0;
}

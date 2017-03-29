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



linkList initialLinklist(void *data,int a) //�����µĽڵ�ռ�
 {
    linkList link = (linkList)malloc(sizeof(struct Node));
    link->data = data;
    link->next = NULL;
    switch(a)//�洢��������
    {
    case 1: link->linkListOutput = intLinkListOutput;break;
    case 2: link->linkListOutput = charLinkListOutput;break;
    case 3: link->linkListOutput = doubleLinkListOutput;break;
    case 4: link->linkListOutput = stringLinkListOutput;break;
    }

    return link;
 }

void EnQueue(QQ *q, void *data,int a) //�ڶ�β����ڵ�
 {
    if((q->head==NULL)&&(q->tail==NULL))    //�����еĶ�ͷ�Ͷ�β��Ϊ��ʱ
    {
        linkList link = initialLinklist(data,a);
        q->head=link;
        q->tail=link;
    }
    else    //�����еĶ�ͷ�Ͷ�β����Ϊ��ʱ
    {
        linkList link = initialLinklist(data,a);
        q->tail->next=link;
        q->tail=link;
    }
 }

void linkListOutput(linkList h)     //�յ��������
 {
  printf("You should point which output function is wanted!\n");
 }

void stringLinkListOutput(linkList h)    //�ַ����������
 {
    printf("%s\t", (char*)(h->data));
    printf("\n");
 }

void intLinkListOutput(linkList h)     //�������������
 {
    printf("%d\t", *(int*)(h->data));
    printf("\n");
 }

void doubleLinkListOutput(linkList h)   //�������������
 {
    printf("%f\t", *(double*)(h->data));
    printf("\n");
 }

void charLinkListOutput(linkList h)     // �ַ����������
 {
    printf("%c\t", *(char*)(h->data));
    printf("\n");
 }

void DestroyQueue(QQ *q)    // ���ٶ���
{
    while(q->head)  //����ͷָ�벻ΪNULLʱ
    {
        DeQueue(q); //����
    }
    printf("����һ�ɹ����٣�\n");
}

void DeQueue(QQ *q) // ����
{
    if(q->head==NULL)
    {
        printf("�����ѿգ�\n");
        return;
    }
    linkList p;
    p=q->head;
    printf("����Ԫ�أ�");
    p->linkListOutput(p);   //�����ͷԪ��
    if(q->head->next!=NULL)
    {
        q->head=q->head->next;
        free(p);
    }
    else
    {
        q->head=NULL;
        q->tail=NULL;
        free(p);
    }
}

void GetHeadQueue(QQ *q)    // ���ض�ͷԪ��
{
    if(q->head==NULL)
    {
        printf("�����ѿգ�\n");
        return;
    }
    q->head->linkListOutput(q->head);
}

void IsEmptyQueue(QQ *q)    // �ж϶����Ƿ�Ϊ��
{
    if(q->head==NULL) printf("Ŀǰ����Ϊ�գ�\n");
    else printf("���в�Ϊ�գ�\n");
}

void output(QQ *q)
{
    linkList p;
    int i=0;    //  ���ڼ���
    p=q->head;
    /*pt=q->tail;
    pt->linkListOutput(pt);*/
    while(p)
    {
        printf("��%d��Ԫ��\t\t",i++);
        p->linkListOutput(p);
        p=p->next;
    }

}

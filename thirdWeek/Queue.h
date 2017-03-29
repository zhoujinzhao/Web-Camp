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


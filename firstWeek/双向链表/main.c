#include <stdio.h>
#include <stdlib.h>
/**  * ˫���������  */
typedef struct TNode {
    int data;
    struct TNode *next;
    struct TNode *pre;
}TNode, *ptr_TNode;
typedef enum Status {
      SUCCESS,ERROR
}Status;
 //����˫������
ptr_TNode create(int *arr, int n);
 ptr_TNode tails(ptr_TNode head);
Status delete_T(ptr_TNode *head, int index, int *data);
Status insert_T(ptr_TNode *head, ptr_TNode node, int index);
void print_next(ptr_TNode head);
void print_pre(ptr_TNode tail);
void destroy(ptr_TNode head);
int main()
{
    int b[8]={1,2,3,4,5,6,7,8},index,data,choice;//indexΪλ�ã�
    ptr_TNode head,tail,node;
    head=create(b,8);                       //����˫������
    tail=tails(head);                       //��ȡβ�ڵ�
    print_next(head);                       //˳�����
    print_pre(tail);                        //�������
    while(1)
    {
        printf("\t\t��ѡ��Ҫ����ʲô����(����1-3)��\n");
        printf("\t\t1������ڵ�\n");
        printf("\t\t2��ɾ���ڵ�\n");
        printf("\t\t3���˳�\n");
        scanf("%d",&choice);        //����Ҫѡ��Ĳ���
        if(choice<0||choice>3)
        {
            printf("�������\t");continue;
        }
        switch(choice)
        {
        case 1: printf("������Ҫ�����λ�ã�");
                scanf("%d",&index);             //indexΪҪ�����λ��
                if(insert_T(&head,node,index)==1)   printf("δ�ɹ����룡\n");//���뺯��
                else print_next(head);break;
        case 2: printf("������Ҫɾ����λ�ã�\n");       //����ɾ��λ��
                scanf("%d",&index);
                if(delete_T(&head,index,&data)==1) printf("û�иýڵ�\n");//data�洢ɾ�����ݣ�ed����ɾ���������ؽ��
                else printf("ɾ����%d\n",data);
                print_next(head);break;
        case 3: destroy(head);return 0;       //��������//��������
        }
    }
    return 0;
}

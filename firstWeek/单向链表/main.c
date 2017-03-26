#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node, *ptr_Node;

typedef enum Status {
    SUCCESS, ERROR
}Status;
ptr_Node create(int *arr, int n);
void destroy(ptr_Node head);
Status insert(ptr_Node *head, ptr_Node node, int index);
Status delete(ptr_Node *head, int index, int *data);
ptr_Node search(ptr_Node head, int data);
 Status edit(ptr_Node head, int index, int *data);
void print(ptr_Node head);
Status sort(ptr_Node *head);
int main()
{
    int a[8]={8,7,6,5,4,3,2,1};     //����
    ptr_Node head,node;             //nodeΪ������½ڵ�
    int index,temp,choice;
    head=create(a,8);               //ת������Ϊ����
    print(head);                    //�����ǰ����
    sort(&head);
    print(head);
    while(1)
    {
        printf("\t\t��ѡ��Ҫ����ʲô����(����1-5)��\n");
        printf("\t\t1������ڵ�\n");
        printf("\t\t2��ɾ���ڵ�\n");
        printf("\t\t3�����ҽڵ�\n");
        printf("\t\t4���޸Ľڵ�\n");
        printf("\t\t5����������\n");
        printf("\t\t6���˳�\n");
        scanf("%d",&choice);        //����Ҫѡ��Ĳ���
        if(choice<0||choice>6)
        {
            printf("�������\t");continue;
        }
        switch(choice)
        {
        case 1: printf("������Ҫ�����λ�ã�");
                scanf("%d",&index);         //indexΪҪ�����λ��
                if(insert(&head,node,index)==1) printf("����ʧ�ܣ�\n");    //���뺯��
                print(head);break;
        case 2: printf("������Ҫɾ���Ľڵ��λ�ã�");
                scanf("%d",&index);         //indexΪҪɾ���Ľڵ��ǰһ��λ��
                if(delete(&head,index,&temp)==1) print("ɾ��ʧ��!\n");   //ɾ������
                else printf("ɾ����%d\n",temp);
                print(head);break;
        case 3: printf("������Ҫ��ѯ�����ݣ�");
                scanf("%d",&index);         //indexΪҪ��ѯ������
                int ad=search(head,index);  //����ad���ղ�ѯ�������صĽ��
                if(ad==-1) printf("�����ݲ�����\n");
                else printf("�����ݵ�λ��Ϊ%d\n",ad);
                print(head);break;
        case 4: printf("������Ҫ�޸ĵ����ݵ�λ�ã�");
                scanf("%d",&index);         //indexΪҪ�޸ĵ����ݵ�λ��
                printf("�������޸ĺ�����ݣ�");
                scanf("%d",&temp);          //tempΪҪ�ĳɵ�����
                int ed=edit(head,index,&temp);//����ed�����޸ĺ������صĽ��
                if(ed==1) printf("�޸Ĵ���\n");
                else printf("%d�ѳɹ��޸�\n",temp);
                print(head);break;
        case 5: destroy(head);break;        //��������
        case 6: return 0;                   //��������
        }
    }
    return 0;
}

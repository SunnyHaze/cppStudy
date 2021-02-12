#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list_node{
    int data;
    struct list_node *next; //������һ�ڵ��ָ��
};

typedef  struct list_node list_single;


//��������ĵ�һ���ڵ㲢�����
// int main(){  
//     list_single *node = NULL;
//     node =(list_single *)malloc(sizeof(list_single) );
//     if(node == NULL)
//         printf("malloc fair!\n");
//     memset(node,0,sizeof(list_single) );
//     node->data = 100;
//     node->next = NULL;
//     printf("%d\n",node->data);
//     free(node);
//     return 0; 
// }

list_single * create_list_node(int data){
    list_single *node = NULL;
    node = (list_single *)malloc(sizeof(list_single) );
    if(node == NULL)
        printf("malloc fair\n");
    memset(node,0,sizeof(list_single) );
    node->data = data;
    node->next = NULL;
    return node;
}

//������β�庯��ԭ�Ͷ��壺0 1 2 3 null -----> 0 1 2 3 later null
void tail_insert(struct list_node *header ,struct list_node *later){
    struct list_node *p = header;
    while(NULL != p->next)
        p = p->next;
    p->next = later;
}

//������ͷ�庯��ԭ�Ͷ��壺     0 header  ----> 0 later header
void top_insert(struct list_node *header, struct list_node *later){
    struct list_node *p = header;
    later->next = p->next ;
    p->next = later;
}

//����������ĺ�����ͷ��㲻��Ҫ��ӡ
void Print_node(struct list_node *head){
    struct list_node *p = head;
    p = p->next;
    while (p->next != NULL){
        printf("node:%d\n",p->data);
        p = p->next;
    }
    printf("node:%d\n",p->data);

    //����һ��һ�д���ʵ�ֱ����̵ķ�ʽ��
    // struct list_node *p = head;    //��ƫ�ƣ���ȡ�����ݡ�
    // while(p->next != NULL){
    //     p = p->next;
    //     printf("node:%d\n",p->data);
    // }
}

//������ڵ��ɾ������ԭ�ͣ�
int delete_list_node(struct list_node *head , int data){
    struct list_node *p = head;
    struct list_node *prev = NULL;
    while(p->next != NULL){
        prev = p;
        p = p->next;
        if(p->data == data){
            if(p->next == NULL){
                prev->next = NULL;
                free(p);
            }
            else{
                prev->next = p->next;
                free(p);
                p = prev->next;
            }
        }
    }
    return 0;
}

//�������������ԭ�ͣ�
void reverse_list(struct list_node *head){
    struct list_node *p = head->next;
    struct list_node *pback;
    if(p == NULL || p->next == NULL)//�޽ڵ����ֻ��һ����Ч�ڵ�
        return;
    while(p->next != NULL){
        pback = p->next;
        if(p == head->next){ //����ǵ�һ����Ч�ڵ㣬ֱ��������Ϊĩβ����
			p->next = NULL;
        }
        else{
            p->next = head->next ; //head��ַʼ�ղ��䣬����ָ�򲻶Ϻ��ơ�
        }
        head->next = p;
        p = pback;
    }
    top_insert(head,p);
}
int main(void){
    int data;
    scanf("%d",&data);
    struct list_node *mylist = create_list_node(0);
    for(int i = 0 ; i != data ; i++){
        tail_insert(mylist,create_list_node(i) );
    }
    Print_node(mylist);
    delete_list_node(mylist,5);
    putchar('\n');
    Print_node(mylist);
    putchar('\n');
    reverse_list(mylist);
    Print_node(mylist);
    return 0;    
}
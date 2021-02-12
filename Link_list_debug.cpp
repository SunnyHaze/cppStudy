#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list_node{
    int data;
    struct list_node *next; //访问下一节点的指针
};

typedef  struct list_node list_single;


//生成链表的第一个节点并输出；
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

//单链表尾插函数原型定义：0 1 2 3 null -----> 0 1 2 3 later null
void tail_insert(struct list_node *header ,struct list_node *later){
    struct list_node *p = header;
    while(NULL != p->next)
        p = p->next;
    p->next = later;
}

//单链表头插函数原型定义：     0 header  ----> 0 later header
void top_insert(struct list_node *header, struct list_node *later){
    struct list_node *p = header;
    later->next = p->next ;
    p->next = later;
}

//单链表遍历的函数：头结点不需要打印
void Print_node(struct list_node *head){
    struct list_node *p = head;
    p = p->next;
    while (p->next != NULL){
        printf("node:%d\n",p->data);
        p = p->next;
    }
    printf("node:%d\n",p->data);

    //另有一种一行代码实现本过程的方式：
    // struct list_node *p = head;    //先偏移，后取用数据。
    // while(p->next != NULL){
    //     p = p->next;
    //     printf("node:%d\n",p->data);
    // }
}

//单链表节点的删除函数原型：
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

//单链表的逆序函数原型：
void reverse_list(struct list_node *head){
    struct list_node *p = head->next;
    struct list_node *pback;
    if(p == NULL || p->next == NULL)//无节点或者只有一个有效节点
        return;
    while(p->next != NULL){
        pback = p->next;
        if(p == head->next){ //如果是第一个有效节点，直接令其作为末尾存在
			p->next = NULL;
        }
        else{
            p->next = head->next ; //head地址始终不变，但是指向不断后移。
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
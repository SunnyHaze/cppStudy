#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct double_list{
    int data;
    struct double_list *prev;
    struct double_list *next;
}list;
list* creat_node(int data){
    list *p = (list*)malloc(sizeof(list));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void double_list_tail_insert(list *header,list *insert){
    list *p = header;
    while (p->next != NULL)
        p = p->next;
    p->next = insert;
    insert->prev = p;
}

void double_list_top_insert(list *header,list *insert){
    insert->prev = header;
    insert->next = header->next;
    header->next->prev = insert;
    header->next =  insert;
}

void double_list_for_each(list *header){
    list *p = header->next;
    while (p->next != NULL){
        printf("node:%d\n",p->data);
        p = p->next;
    }
    printf("node:%d\n",p->data);
}

void double_list_for_each_nx(list *header){
    list *p = header;
    while(p->next != NULL)
        p = p->next;
    while (p->prev != NULL){
        printf("node:%d\n",p->data);
        p = p->prev;
    }
    
}

void double_list_delete(list *header, int data){
    list *p = header;
    while (p->next != NULL){
        p = p->next;
        if(p->data == data){
            if(p->next != NULL){
                p->next->prev = p->prev;
                p->prev->next = p->next;
                free(p);
            }
            else{
                p->prev->next = NULL;
                free(p);
            }
        }
    }
    
}

int main(){
    list *mylist = creat_node(0); 
    for(int i = 0 ; i < 10 ; i++){
        double_list_tail_insert(mylist , creat_node(i));
    }
    double_list_for_each(mylist);
    putchar('\n');
    double_list_for_each_nx(mylist);
    double_list_delete(mylist,5);
}
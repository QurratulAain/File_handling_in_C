#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

struct Node* CreateNode(int data){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    if (newnode==NULL){
        fprintf(stderr,"memory failed \n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void LinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;}
}
struct Node* insertAtBeg(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node*insertAtINdex(struct Node*head,int data,int index){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    int i=0;
    struct Node*p=head;
    while(i<(index-1)){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node*insertAtEnd(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    return head;
}
struct Node*insertAfterNode(struct Node*head,struct Node*prevNode,int data){
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=data;
        ptr->next=prevNode->next;
        prevNode->next=ptr;
        return head;
}
struct Node*DeletingFirstNode(struct Node*head){
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node*DeletingNodeBetween(struct Node*head,int index){
    struct Node*p=head;
    int i=0;
    while(i<(index-1)){
        p=p->next;
        i++;
    }
    struct Node*q=p->next;
    p->next=q->next;
    free(q);
    return head;
}
struct Node*DeletingLastNode(struct Node*head){
    struct Node*p=head;
    struct Node*q=p->next;
    int i=0;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
        i++;
    }
    
    p->next=NULL;
    free(q);
    return head;
}
struct Node*DeletingByValue(struct Node*head,int value){
    struct Node*p=head;
    struct Node*q=p->next;
    int i=0;
    while(q->next!=NULL && q->data!=value){
       p=p->next;
        q=q->next;
        i++;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
}
struct Node*SearchByValue(struct Node*head,int value){
    struct Node*p=head;
    while (p!=NULL){
        if (p->data==value){
            return p;

        }p=p->next;
    }return NULL;
}
void freelist(struct Node* head){
    struct Node* current=head;
    while(current!=NULL){}
        struct Node* temp=current;
        current=current->next;
        free(temp);
}

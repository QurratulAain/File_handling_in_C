#include<stdio.h>
#include<string.h>
#include"linkedlist.h"

int main(){
    struct Node*head=CreateNode(4);
    //LinkedListTraversal(head);
    printf(" \n");
    head=insertAtBeg(head,1);
    head=insertAtBeg(head,9);
    head=insertAtBeg(head,15);
    head=insertAtEnd(head,6);
    head=insertAtEnd(head,7);

    // LinkedListTraversal(head);
    // DeletingByValue(head,7);

    // LinkedListTraversal(head);
    int searchvalue=4;
    struct Node*foundNode=SearchByValue(head,searchvalue);
    if (foundNode!=NULL){
        printf("Node with value %d found\n",searchvalue);

    }else{
        printf("Node with value %d not found\n",searchvalue);
    }
    LinkedListTraversal(head);
   freelist(head);
    return 0;

}

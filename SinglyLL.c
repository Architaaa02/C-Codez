//CRUD operations on singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node* link;
};

struct Node* head = NULL; // Starting node of the list

void CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    (*newNode).data = data;  // Assign data to the new node
    (*newNode).link = NULL;

    if (head == NULL) { 
        // If the list is empty, set head to the new node
        head = newNode;
    } else {
        // Otherwise, find the last node and add the new node at the end
        struct Node* next = head;
        while ((*next).link != NULL) {
            next = (*next).link;
            // It moves 'next' to the next node (next = (*next).link), effectively traversing the list one node at a time.
        }
        (*next).link = newNode;
        //The line (*next).link = newNode; sets the link (or next pointer) of the last node to point to newNode, effectively adding newNode at the end of the list.
    }
}

void Traverse() {
    struct Node* current = head;
    if (current == NULL) {
        printf("Linked list is empty!!!\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d\n", (*current).data);
        current = (*current).link;
    }
}

void InsertAtPosition(int data, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("memory allocation failed");
        return ; 
    }
    (*newNode).data=data;
    (*newNode).link=NULL;

    if(pos==1){
        (*newNode).link=head;
        head=newNode;
        return;
    }

    struct Node* temp=head; //This initializes a pointer temp to point to the head of the linked list. This pointer will be used to traverse the list.
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp = (*temp).link;// // Move to the (n-1)th node
    }
    //The goal is to find the (n-1)th node so we can insert the new node right after it.
    
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);  // Free allocated memory if position is invalid
        return;
    }
    (*newNode).link = (*temp).link;  // Insert the new node
    (*temp).link = newNode;
}

void DeletePosNode(int pos){

    if(head==NULL){
        printf("Linked list is empty, notjing to delete.");
        return; 
    }

    struct Node* temp= head;
    //temp is used to traverse the list to find the node that we want to delete.

    if(pos==1){ 
        //if head needs to be removed.
        head=(*head).link;//statement to make the 2nd node of the list as head.
        free(temp);//since we took head as temp, freeing temp will remove first node of the list.
        return;
    }

    struct Node* prev = NULL;
    //prev is used to keep track of the node immediately before the node that we want to delete.

    //'temp' starts at the head and is used to traverse the list.
    //'prev' starts as NULL and is updated in each iteration to point to the node just before temp.

    for(int i=1; i<pos-1 && temp!=NULL; i++){
        prev = temp; // Keep track of the previous node
        temp=(*temp).link; //// Move to the next node
    }

    if(temp==NULL){
        printf("Position out of bound.");
        return;
    }

    (*prev).link=(*temp).link; // Re-link to skip the nth node
    printf("\nThe Position %d\n", pos-1);
    free(temp);
}

void SortLinkedList(){
    struct Node* curr=head;
    struct Node* index=NULL;
    int temp;

    if(head==NULL){
        printf("Linked list is empty, nothing to sort.");
        return;
    }else{
        while(curr!=NULL){
            index=(*curr).link;

            while(index!=NULL){
                if((*curr).data > (*index).data){
                    temp = (*curr).data;
                    (*curr).data = (*index).data;
                    (*index).data = temp;
                }
                index = (*index).link;
            }
            curr = (*curr).link;
        }
    }
}

void SearchNode(int value){

    struct Node* curr = head;
    int pos=1;

    while(curr!=NULL){
        //To check if the current node's data matches the value.
        if((*curr).data==value){ 
            printf("The Node with value %d found at position %d.\n", value, pos);
            return;
        }
        curr = (*curr).link; // Move to the next node
        pos++; // Increment position
    }
    printf("Node with value %d not found in the list.\n", value);
}

int main() {
    CreateNode(3);
    CreateNode(6);
    CreateNode(10);
    CreateNode(5);
    CreateNode(9);
    CreateNode(11);
    CreateNode(2);
    CreateNode(4);
    CreateNode(8);
    printf("The linked list is:\n"); 
    Traverse();
    
    InsertAtPosition(12, 7);
    printf("\nThe linked list after insertion is:\n"); 
    Traverse();

    DeletePosNode(4);
    printf("\nLinked list after the deletion of node.\n");
    Traverse();

    SearchNode(9);

    printf("\nSorted linked list:\n");
    SortLinkedList();
    Traverse();
    
    return 0;
}

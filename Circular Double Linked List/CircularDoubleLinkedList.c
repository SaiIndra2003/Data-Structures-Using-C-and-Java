#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev, newNode->next = NULL;
    return newNode;
}

int getSize(struct Node* head){

    struct Node* temp = head;
    int size = 0;

    if(temp == NULL){
        return 0;
    }

    if(temp->next == NULL){
        size = 1;
        return size;
    }

    do{
        size++;
        temp = temp->next;
    } while (temp!=head);

    return size;
}

void printList(struct Node* head){

    struct Node* temp = head;

    if(head ==NULL){
        printf("Empty List...");
    }

    printf("List is : ");
    while(temp->next != head){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;

}


void Insert(struct Node** head,int data,int pos){

    struct Node* temp = *head;
    struct Node* newNode = createNode(data);
    int size = getSize(*head);

    if(*head == NULL){
        // Empty List
        *head = newNode;
        return;
    }

    if(pos>size){
        pos = 0;
    }

    if(pos==1){
        // Inserting at the begining of List
        printf("Inserting at the beggining of the list...\n");
        newNode->next = temp; 
        
        if(size == 1){
            newNode->prev = temp;
            temp->next = newNode;
        }
        else{
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
        }

        temp->prev = newNode;
        *head = newNode;

        return;
    }

};

int main(){

    struct Node* head = NULL;

    Insert(&head,2,1);
    Insert(&head,1,1);
    printList(head);

}
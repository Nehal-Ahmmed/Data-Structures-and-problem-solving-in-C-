#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void displayList(struct Node *ptr){
    while (ptr != NULL)
    {
        cout<< ptr -> data <<" -> ";
        ptr = ptr -> next;
    }
    cout<<"NULL"<<endl;
}

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = new Node();
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

struct Node *insertAtPosition(struct Node *head, int data, int index){
    struct Node *ptr = new Node();
    struct Node *temp = head;
    int i= 0;

    while(i!= index-1){
        temp = temp->next;
        i++;
    }

    ptr->next = temp->next;
    ptr->data = data;
    temp->next = ptr;

    return head;
}

struct Node *deleteLast(struct Node *head){
    struct Node *temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    temp->next = NULL;
    return head;

}

struct Node *deleteAtPosition(struct Node *head, int index){
    struct Node *temp = head;
    int i =0;

    while(i!= index-1){
        temp = temp->next;
        i++;
    }

    temp = temp->next->next;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = NULL;

    cout<<"Linked list before insertion "<<endl;
    displayList(head);

    head = insertAtFirst(head, 56);
    cout<<"Linked list after insertion at first "<<endl;
    displayList(head);

    head = insertAtPosition(head, 99, 2);
    cout<<"Linked list after insertion at position 2 "<<endl;
    displayList(head);

    head = deleteLast(head);
    cout<<"Linked list after deletion at last "<<endl;
    displayList(head);

    head = deleteAtPosition(head, 2);
    cout<<"Linked list after deletion at position 2 "<<endl;
    displayList(head);

    return 0;
}
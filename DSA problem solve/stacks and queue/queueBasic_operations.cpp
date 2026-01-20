#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    int count ;
    Node *Top;
};

void traverse(Queue *q){

    while(q->Top != NULL){
        cout<<q->Top->data<<" ";
        q->Top = q->Top->next;
    }

    cout<<endl;
}

void insert(Queue *q, int data){
    Node *newNode = new Node();
    newNode->data = data;

    newNode->next = q->Top;
    q->Top  = newNode;
    q->count++;
}

void deleteElement(Queue *q){
    Node *temp = q->Top;
    while (temp->next->next!=NULL)
    {
        temp= temp->next;
    }
    
    temp->next= NULL;
    q->count--;
}


int main(){

    Queue *q = new Queue();

    insert(q,10);
    insert(q,20);
    insert(q,30);
    insert(q,40);

    deleteElement(q);
    cout<<"after traversing"<<endl;
    traverse(q);

}
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    Node *front;
    Node *rear;
    int count;
};

Queue* createQueue(){
    Queue *q = new Queue();
    q->front= q->rear = NULL;
    q->count=0;

    return q;
}

//insert at rear
void insert(Queue *q, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(q->rear == NULL){
        q->rear = q->front = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    cout<<"inserted "<<data<<" into queue and total  element is : "<<q->count<<endl;
}

//delete from front
void deleteElement(Queue *q){
    if(q->rear == NULL){
        cout<<"queue is empty"<<endl;
        return;
    }

    cout<<"deleted "<<q->front->data<<" from queue ";
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    q->count--;
    cout<<"and total element is: "<<q->count<<endl;

}

void traverse(Queue *q){
    if(q->front == NULL && q->rear == NULL){
        cout<<"queue is empty"<<endl;
        return;
    }

    while(q->front != NULL){
        cout<<q->front->data<<" ";
        q->front = q->front->next;
    }

    q->rear = NULL;
    cout<<endl;
    q->count = 0;
    cout<<"queue traversed and now it is empty"<<endl;
}

int main(){
    Queue *q = createQueue();

    insert(q,10);
    insert(q,20);
    insert(q,30);
    insert(q,40);

    deleteElement(q);
    deleteElement(q);

    traverse(q);
    traverse(q);
}
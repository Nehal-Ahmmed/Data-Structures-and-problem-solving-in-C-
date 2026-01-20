#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Dequeue{
    Node *front;
    Node *Rear;
    string name = "Nehal Ahmmed";
    int count =0;
};

Dequeue* createQueue(){
    Dequeue *dq= new Dequeue();
    dq->front = dq->Rear = NULL;
    cout<<"Dequeue created"<<endl;
    return dq;
}

//insert at front and delete at rear
void insertAtFront(Dequeue *dq, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(dq->Rear == NULL || dq->front == NULL){
        dq->front = dq->Rear = newNode;
    }else{
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->count++;
    cout<<"inserted "<<data<<" into dequeue and total element is : "<<dq->count<<endl;
}

void deleteElementAtRear(Dequeue *dq){
    if(dq->Rear == NULL){
        cout<<"dequeue is empty"<<endl;
        return;
    }
    cout<<"deleted "<<dq->Rear->data<<" from dequeue ";
    dq->Rear = dq->Rear->prev;
    dq->count--;
    cout<<"and total element is: "<<dq->count<<endl;
    if(dq->Rear == NULL){
        dq->front = NULL;
    }
}

void traversefromRearToFront(Dequeue *dq){
    if(dq->front == NULL && dq->Rear == NULL){
        cout<<"dequeue is empty"<<endl;
        return;
    }
    while(dq->Rear != NULL){
        cout<<dq->Rear->data<<" ";
        dq->Rear = dq->Rear->prev;
    }
    dq->front = NULL;
    cout<<endl;
    cout<<"dequeue traversed from rear to front"<<endl;
    dq->count=0;
}


//insert at rear and delete at front
void insertAtRear(Dequeue *dq, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(dq->Rear == NULL || dq->front == NULL){
        dq->front = dq->Rear = newNode;
    }else{
        newNode->prev = dq->Rear;
        dq->Rear->next = newNode;
        dq->Rear = newNode;
    }
    dq->count++;
    cout<<"inserted "<<data<<" into dequeue and total element is : "<<dq->count<<endl;
}

void deleteElementAtFront(Dequeue *dq){
    if(dq->Rear == NULL){
        cout<<"dequeue is empty"<<endl;
        return;
    }
    cout<<"deleted "<<dq->front->data<<" from dequeue ";
    dq->front = dq->front->next;
    dq->count--;
    cout<<"and total element is: "<<dq->count<<endl;

    if(dq->front == NULL){
        dq->Rear = NULL;
    }
}

void traversefromFrontToRear(Dequeue *dq){
    if(dq->front == NULL && dq->Rear == NULL){
        cout<<"dequeue is empty"<<endl;
        return;
    }
    while(dq->front != NULL){
        cout<<dq->front->data<<" ";
        dq->front = dq->front->next;
    }
    dq->Rear = NULL;
    cout<<endl;
    cout<<"dequeue traversed from rear to front"<<endl;
    dq->count=0;
}

int main(){
    Dequeue *dq = createQueue();

    insertAtFront(dq,10);
    insertAtFront(dq,20);
    insertAtFront(dq,30);
    insertAtFront(dq,40);

    deleteElementAtRear(dq);
    cout<<"after traversing from rear to front"<<endl;
    traversefromRearToFront(dq);

    insertAtRear(dq,100);
    insertAtRear(dq,200);
    insertAtRear(dq,300);
    insertAtRear(dq,400);

    deleteElementAtFront(dq);
    cout<<"after traversing from front to rear"<<endl;
    traversefromFrontToRear(dq);
}
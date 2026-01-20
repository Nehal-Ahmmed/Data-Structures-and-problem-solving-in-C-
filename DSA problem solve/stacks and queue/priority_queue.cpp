#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *next;
    Node *prev;
};
struct PtQueue{
    Node *front;
    Node *rear;
    int count;
};

PtQueue* createPriorityQueue(){
    PtQueue *pq = new PtQueue();
    pq->front = pq->rear = NULL;
    pq->count =0;
    cout<<"priority queue created"<<endl;
    return pq;
}

void insertAtPtQueue(PtQueue *pq, int data, int priority){
    Node *newnode = new Node();
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = newnode->prev = NULL;

    if(pq->front == NULL || pq->rear == NULL){
        pq->front = pq->rear = newnode;
    }else{
        Node *temp = pq->front;
        while(temp != NULL && temp->priority >= priority){
            temp = temp->next;
        }

        if(temp == NULL){
            newnode->prev = pq->rear;
            pq->rear->next = newnode;
            pq->rear = newnode;
        }else if(temp == pq->front){
            newnode->next = pq->front;
            pq->front->prev = newnode;
            pq->front = newnode;
        }else{
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
        }
    }
    pq->count++;
    cout<<"inserted "<<data<<" with priority "<<priority<<" into priority queue and total element is : "<<pq->count<<endl;
}

void deletePriorityQueue(PtQueue *pq) {
    if (pq->front == NULL) {
        cout << "Priority Queue is empty" << endl;
        return;
    }
    cout << "Deleted " << pq->front->data << " with priority " << pq->front->priority << " from queue ";
    pq->front = pq->front->next;
    pq->count--;
    if(pq->front == NULL) {
        pq->rear = NULL;
    }
    cout << "and total element is: " << pq->count << endl;
}

void traversePriorityQueue(PtQueue *pq) {
    if (pq->front == NULL && pq->rear == NULL) {
        cout << "Priority Queue is empty" << endl;
        return;
    }
    cout << "Priority Queue elements (highest priority first): ";
    while (pq->front != NULL)
    {
        cout << "(" << pq->front->data << ", " << pq->front->priority << ") ";
        pq->front = pq->front->next;
    }
    pq->count = 0;
    cout <<"Priority Queue traversed from highest to lowest priority" << endl;
    pq->rear = NULL;

}

int main(){
    PtQueue *pq = createPriorityQueue();

    insertAtPtQueue(pq, 10, 2);
    insertAtPtQueue(pq, 20, 1);
    insertAtPtQueue(pq, 30, 3);
    insertAtPtQueue(pq, 40, 4);

    deletePriorityQueue(pq);
    cout << "after traversing" << endl;
    traversePriorityQueue(pq);
}
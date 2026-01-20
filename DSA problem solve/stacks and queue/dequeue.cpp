#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Queue {
    int count;
    string name = "NehalAhmmed's Stack";
    Node *top;
};

void insertFront(Queue *dq, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = dq->top;
    newNode->prev = NULL;

    if (dq->top != NULL) {
        dq->top->prev = newNode;
    }
    dq->top = newNode;
    dq->count++;
}

void insertRear(Queue *dq, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (dq->top == NULL) {
        newNode->prev = NULL;
        dq->top = newNode;
    } else {
        Node *temp = dq->top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    dq->count++;
}

void deleteFront(Queue *dq) {
    if (dq->top == NULL) {
        cout << "Deque is empty!" << endl;
        return;
    }

    Node *temp = dq->top;
    dq->top = dq->top->next;

    if (dq->top != NULL) {
        dq->top->prev = NULL;
    }

    delete temp;
    dq->count--;
}

void deleteRear(Queue *dq) {
    if (dq->top == NULL) {
        cout << "Deque is empty!" << endl;
        return;
    }

    Node *temp = dq->top;

    if (temp->next == NULL) {
        dq->top = NULL;
        delete temp;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    dq->count--;
}

void traverse(Queue *dq) {
    
    while (dq->top != NULL) {
        cout << dq->top->data << " ";
        dq->top = dq->top->next;
    }
    cout << endl;
}




int main() {
    Queue *dq = new Queue();
    dq->count = 0;
    dq->top = NULL;

    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 30);
    insertRear(dq, 40);
    insertFront(dq, 5);


    deleteFront(dq);
    

    deleteRear(dq);
    

    cout<<"total number of elements: "<<dq->count<<endl;
    traverse(dq);
    traverse(dq);

    return 0;
}
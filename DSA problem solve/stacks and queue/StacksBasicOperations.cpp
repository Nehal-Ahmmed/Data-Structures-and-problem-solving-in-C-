#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    string stackName="nehal's stack";
    Node *Top;
    int count;
};

void traverse(Stack *stack){
    if(stack->Top == NULL){
        cout<<"stack is empty"<<endl;
        return;
    }
    while(stack->Top != NULL){
        cout<<stack->Top->data<<" ";
        stack->Top = stack->Top->next;
    }
    stack->count=0;
    cout<<"stack traversed from top to bottom"<<endl;
    cout<<endl;
}

void insert(Stack *stack, int info){
    Node *newNode = new Node();
    newNode->data = info;
    newNode->next= stack->Top;
    stack->Top = newNode;
    stack->count++;
    cout<<"inserted "<<info<<" into stack and total element is : "<<stack->count<<endl;
}

void deleteElement(Stack *st ){
    if(st->Top == NULL){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<"deleted "<<st->Top->data<<" from stack ";
    st->Top = st->Top->next;
    st->count--;
    cout<<"and total element is: "<<st->count<<endl;
}

int main(){
    Stack *st = new Stack();
    st->count= 0;
    st->Top = NULL;
    insert(st, 10);
    insert(st,20);
    insert(st,30);
    deleteElement(st);
    traverse(st);
    traverse(st);
}
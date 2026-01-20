#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct HeaderNode {
    int count;          
    string name= "NehalAhmmed's List";      
    Node *next;         
};


void insertAtFirst(HeaderNode *header, int data) {
    Node *newNode = new Node();
    newNode->data = data;

    newNode->next = header->next;
    header->next = newNode;
    header->count++;
}



void insertAtEnd(HeaderNode *header, int data){

    Node *newNode = new Node();
    newNode->data= data;
    Node *temp = header->next;
    

    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next= newNode;
    newNode->next= NULL;
    header->count++;


}

void insertAtPosition(HeaderNode *header,int pos, int data){
    if(pos>header->count){
        cout<<"invalid position";
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    Node *temp = header->next;

    int i=1;
    while (i<=pos-2)
    {
        temp= temp->next;
       i++;
    }
    

    newNode->next= temp->next;
    temp->next= newNode;
    header->count++;
}

void deleteAtPos(HeaderNode *header, int pos){
    if(pos>header->count){
        cout<<"invalid position";
        return;
    }

    Node *temp = header->next;

    int i=1;
    while (i<=pos-2)
    {
        temp= temp->next;
       i++;
    }

    temp->next= temp->next->next;
    header->count--;
}

void deleteAnyElement(HeaderNode *header, int element){
    
    Node *temp = header->next;

    while (temp->next->data != element)
    {
        temp= temp->next;
    }

    temp->next= temp->next->next;
    header->count--;
}

void searchAnyElement(HeaderNode *header , int data){
    Node *temp = header->next;
    bool flag = false;

    while(temp!=NULL){
        if(temp->data == data){
            flag= true;
            cout<<"The element "<<data<<" found"<<endl;
            break;
        }
    }

    if(!flag){
        cout<<"element not found"<<endl;
    }

}

void addElementAtEndOfCircularList(HeaderNode *header, int data){
    Node *newNode = new Node();
    newNode->data= data;
    Node *temp = header->next;
    

    while(temp->next!=header->next){
        temp= temp->next;
    }

    temp->next= newNode;
    newNode->next= header->next;
    header->count++;

}

void display(HeaderNode *header) {
    cout << "List Name: " << header->name << endl;
    cout << "Node Count: " << header->count << endl;
    cout << "List: ";

    Node *ptr = header->next;
    while(ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}



int main() {

    HeaderNode *header = new HeaderNode();
    header->count = 0;
    header->next = NULL;      

    insertAtFirst(header, 10);
    insertAtFirst(header, 20);
    insertAtFirst(header, 30);

    display(header);

    insertAtEnd(header,40);
    cout<<"after adding at last"<<endl;
    display(header);

    insertAtPosition(header,2,90);
    cout<<"after adding at a position"<<endl;
    display(header);

    deleteAtPos(header,2);
    cout<<"after deleting at a position"<<endl;
    display(header);


    deleteAnyElement(header,20);
    cout<<"after deleting any element "<<endl;
    display(header);

    searchAnyElement(header,10);
    cout<<"after searching any element "<<endl;
    display(header);


    return 0;
}

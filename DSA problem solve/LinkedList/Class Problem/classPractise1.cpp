#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *ptr = head;
    while(ptr!=NULL){
        cout<< ptr->data <<" -> ";
        ptr = ptr->next;
    }

    cout<<"NULL";
    cout<<endl;
}

//2 searching (unsorted)
void searchUnsorted(struct Node *head){
    int k;
    cout<<"insert the key value you wanna search : ";
    cin>>k;

    struct Node *temp = head;
    int i=1;
    int count=0;

    while(temp != NULL){
        if(temp->data == k){
            cout<< "Element found at index " << i <<" ";
        }
        i++;
        temp = temp->next;
    }

    if(count > 0){
        cout<<"found : "<<count<<" times";
    }else{
    cout<< "Element not found";
    }
}

void searchSorted(struct Node *head){
    int k;
    cout<<"insert the key value you wanna search : ";
    cin>>k;

    struct Node *temp = head;
    int i=1;
    int count =0; 

    while(temp != NULL){
        if(temp->data == k){
            cout<< "Element found at index " << i<<" ";
        }
        else if(temp->data > k){
            cout<< "Element not found";
            return;
        }
        temp = temp->next;
    }

    if(count > 0){
        cout<<"found : "<<count<<" times";
    }else{
    cout<< "Element not found";
    }

    return;
}

struct Node *insertAtbegining(struct Node *head){
    int data;
    cout<<"insert the data you wanna add at beginning : ";
    cin>>data;

    struct Node *newNode = new Node();

    newNode->data = data;
    newNode->next = head;

    return newNode;
}

void insertAtIndex(struct Node *head){
    int data;
    cout<<"insert the data you want to add at an index: ";
    cin>>data;

    int i;
    cout<<"insert the index : ";
    cin>>i;

    struct Node *newNode = new Node();
    struct Node *temp = head;
    int index = 1;

    while(index < i-1){
        temp = temp->next;
        index++;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(struct Node *head){
    int data;
    cout<<"insert the data you want to add at end: ";
    cin>>data;
    struct Node *newNode = new Node();
    struct Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->data = data;
    newNode->next = NULL;
    temp->next = newNode;
}

void insertAtsortedlist(struct Node *head){
    int value;
    cout<<"insert the data you want to add to a sorted list: ";
    cin>>value;

    struct Node *newNode = new Node();
    struct Node *temp = head;


    while(value > temp->data){
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtLoc(struct Node *head){
    int loc;
    cout<<"insert the location from which you want to delete : ";
    cin>>loc;

    struct Node *temp = head;
    int i=2;

    while(i<loc){
        if(temp == NULL){
            cout<<"do not exist position";
        }
        temp = temp->next;
        i++;
    }

    temp->next=temp->next->next;
}

void deleteAnItem(struct Node *head){

    int item;
    cout<<"insert the item you want to delete : ";
    cin>>item;

    struct Node *temp = head;

    while (temp != NULL)
    {
        if(temp->next->data == item){
            break;
        }
        temp = temp->next;
    }

    temp->next = temp->next->next;
    
}


int main(){
    struct Node *head;
    struct Node *testnode1;
    struct Node *tstnode2;

    head = new Node();
    testnode1= new Node();
    tstnode2= new Node();


    head->data = 7;
    head->next = testnode1;

    testnode1->data= 9;
    testnode1->next= tstnode2;

    tstnode2->data= 10;
    tstnode2->next = NULL;

    cout<<"your current list (dummy data for testing) : ";
    display(head);

    head=insertAtbegining(head);
    display(head);

    insertAtEnd(head);
    display(head);

    insertAtIndex(head);
    display(head);

    deleteAtLoc(head);
    display(head);

    deleteAnItem(head);
    display(head);

    searchUnsorted(head);
    
    searchSorted(head);
    
    insertAtsortedlist(head);
    display(head);

    return 0;
}
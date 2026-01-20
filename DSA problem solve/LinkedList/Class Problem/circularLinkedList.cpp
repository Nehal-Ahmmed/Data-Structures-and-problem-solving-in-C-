#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct HeaderNode {
    int count;
    string name = "NehalAhmmed's List";
    Node *next;
};

void insertAtFirst(HeaderNode *header, int data) {
    Node *newNode = new Node();
    newNode->data = data;

    if (header->next == NULL) {
        newNode->next = newNode;
        header->next = newNode;
    } else {
        Node *temp = header->next;
        while (temp->next != header->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = header->next;
        header->next = newNode;
    }
    header->count++;
}

void insertAtEnd(HeaderNode *header, int data) {
    if (header->next == NULL) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = newNode;
        header->next = newNode;
        header->count++;
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    Node *temp = header->next;

    while (temp->next != header->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = header->next;
    header->count++;
}

void insertAtPosition(HeaderNode *header, int pos, int data) {

    if (pos == header->count + 1) {
        insertAtEnd(header, data);
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    Node *temp = header->next;

    int i = 1;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    header->count++;
}

void searchElement(HeaderNode *header, int element) {
    if (header->next == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node *current = header->next;
    int position = 1;
    
    do {
        if (current->data == element) {
            cout << "Element " << element << " found at position " << position << endl;
            return ;
        }
        current = current->next;
        position++;
    } while (current != header->next);
    
    cout<<"not found"<<endl;
    return ;
}

void deleteAnyElement(HeaderNode *header, int element) {
    if (header->next == NULL) {
        cout<<"empty list or invalid "<<endl; 
        return;
    }
    
    Node *current = header->next;
    Node *prev = NULL;
    
    while(current->next != header->next && current->data != element) {
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    header->count--;
    return;
}

void deleteAtPosition(HeaderNode *header, int position) {
    if (header->next == NULL || position < 1) {
        cout<<"empty list or invalid position"<<endl; 
        return;
    }
    
    Node *current = header->next;
    Node *prev = NULL;
    
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    header->count--;
    return;
}

void display(HeaderNode *header) {
    if (header->next == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List Name: " << header->name << endl;
    cout << "Node Count: " << header->count << endl;
    cout << "List: ";

    Node *ptr = header->next;

    do {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    } while (ptr != header->next);

    cout << endl;
}

int main() {
    HeaderNode *header = new HeaderNode();
    header->count = 0;
    header->next = NULL;

    insertAtFirst(header, 10);
    insertAtFirst(header, 20);
    insertAtFirst(header, 30);
    cout<<"After Inserting at first: "<<endl;
    display(header);

    insertAtEnd(header, 40);
    cout << "After adding at last" << endl;
    display(header);

    insertAtPosition(header, 2, 90);
    cout << "After adding at a position" << endl;
    display(header);

    deleteAtPosition(header, 2);
    cout << "After deleting at a position" << endl;
    display(header);

    cout<<"Searching for element 40: "<<endl;
    searchElement(header, 40);
    
    deleteAnyElement(header, 30);
    cout << "After deleting any element " << endl;
    display(header);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int m = 3;

struct Node{
    int value[m-1];
    Node *child[m];
};

Node* createNode(){
    Node *newNode = new Node();
    for(int i = 0; i < m-1; i++){
        newNode->value[i] = 0;
    }
    for(int i = 0; i < m; i++){
        newNode->child[i] = nullptr;
    }
    return newNode;
}

void preorder(Node *root){
    if(root == nullptr) return;
    for(int i = 0; i < m-1; i++){
        if(root->value[i] != 0)
    cout << root->value[i]<< " ";
    }
    preorder(root->child[0]);
    preorder(root->child[1]);
    preorder(root->child[2]);
}


void insert(Node *root , int key){
    if(root == nullptr) return;
    int flag =0 ;

    for(int i = 0; i < m-1; i++){
    if(root->value[i] == 0){
        root->value[i] = key;
        flag =1;
        return;
    }
}

if(flag == 0){
    Node *newNode = new Node();
    newNode->value[0] = key;

    if(key < root->value[0] && root->child[0] == nullptr){
        root->child[0] = newNode;
        return;
    }
    else if(key > root->value[0] && key < root->value[1] && root->child[1] == nullptr){
        root->child[1] = newNode;
        return;
    }
    else if(key > root->value[1] && root->child[2] == nullptr){
        root->child[2] = newNode;
        return;
    }
}



    if(key<root->value[0]){
        insert(root->child[0], key);
        return;
    }

    if(key>root->value[0] && key<root->value[1]){
       insert(root->child[1], key);
       return; 
    }

    if(key>root->value[1]){
        insert(root->child[2], key);
        return;
    }
}

int main(){
    Node *root = createNode();
    root->value[0] = 10;
    root->value[1] = 20;
    
    root->child[0] = createNode();
    root->child[0]->value[0] = 5;

    root->child[1] = createNode();
    root->child[1] -> value[0] = 15;
    
    root->child[2] = createNode();
    root->child[2]->value[0] = 25;

    cout << "Root Values: ";
    for(int i = 0; i < m-1; i++){
        if(root->child[0]->value[i] != 0){
            cout << root->child[0]->value[i] << " ";
        }
    }
    cout << endl;

    cout << "Preorder Traversal of M-way Tree: ";
    preorder(root);
    cout << endl;

    cout << "Inserting into M-way Tree" << endl;
    insert(root, 7);

    cout << "Preorder Traversal after Insertion: ";
    preorder(root);

    cout<< "inserting 6: "<<endl;
    insert(root, 6);

    cout << "Preorder Traversal after Insertion: ";
    preorder(root);
    cout << endl;

    cout<< "inserting 16: "<<endl;
    insert(root, 16);

    cout << "Preorder Traversal after Insertion: ";
    preorder(root);
    cout << endl;

    cout<< "inserting 17: "<<endl;
    insert(root, 17);

    cout << "Preorder Traversal after Insertion: ";
    preorder(root);
    cout << endl;



    return 0;
}




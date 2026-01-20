#include<bits/stdc++.h>
using namespace std;

const int m = 3;

struct Node{
    int value[m-1];
    int count;
    Node *child[m];
};

Node* createNode();
void preorder(Node *root);
void insert(Node* root, int key);
bool search(Node* root, int key);
Node* deleteKey(Node* root, int key);

Node* createNode(){
    Node *newNode = new Node();
    newNode->count = 0;
    for(int i = 0; i < m-1; i++){
        newNode->value[i] = -1;
    }
    for(int i = 0; i < m; i++){
        newNode->child[i] = nullptr;
    }
    return newNode;
}

void preorder(Node *root){
    if(root == nullptr) return;
    for(int i = 0; i < root->count; i++){
        if(root->value[i] != -1)
            cout << root->value[i] << " ";
    }
    for(int i = 0; i < m; i++){
        preorder(root->child[i]);
    }
}

bool search(Node* root, int key){
    if(root == nullptr) return false;
    
    for(int i = 0; i < root->count; i++){
        if(root->value[i] == key) return true;
    }
    
    for(int i = 0; i < m; i++){
        if(search(root->child[i], key)) return true;
    }
    
    return false;
}

void insert(Node* root, int key){
    if(root == nullptr) return;
    
    if(root->count < m-1){
        for(int i = 0; i < root->count; i++){
            if(root->value[i] == key) return;
        }
        root->value[root->count] = key;
        root->count++;
    }
    else{
        for(int i = 0; i < root->count; i++){
            if(root->value[i] == key) return;
        }
        
        for(int i = 0; i < m; i++){
            if(root->child[i] == nullptr){
                root->child[i] = createNode();
                root->child[i]->value[0] = key;
                root->child[i]->count = 1;
                return;
            }
        }
        
        for(int i = 0; i < m; i++){
            insert(root->child[i], key);
            return;
        }
    }
}

Node* deleteKey(Node* root, int key){
    if(root == nullptr) return nullptr;
    
    bool foundInCurrent = false;
    int foundIndex = -1;
    
    for(int i = 0; i < root->count; i++){
        if(root->value[i] == key){
            foundInCurrent = true;
            foundIndex = i;
            break;
        }
    }
    
    if(foundInCurrent){
        for(int i = foundIndex; i < root->count-1; i++){
            root->value[i] = root->value[i+1];
        }
        root->count--;
        root->value[root->count] = -1;
        
        if(root->count == 0){
            bool hasChildren = false;
            for(int i = 0; i < m; i++){
                if(root->child[i] != nullptr){
                    hasChildren = true;
                    break;
                }
            }
            
            if(!hasChildren){
                delete root;
                return nullptr;
            }
        }
        return root;
    }
    
    for(int i = 0; i < m; i++){
        if(root->child[i] != nullptr){
            root->child[i] = deleteKey(root->child[i], key);
        }
    }
    
    return root;
}

int main(){
    Node *root = createNode();
    
    cout << "Inserting values into M-way Tree:\n";
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Search 15: " << (search(root, 15) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not Found") << endl;
    
    cout << "\nDeleting 15\n";
    root = deleteKey(root, 15);
    cout << "Preorder after deletion: ";
    preorder(root);
    cout << endl;
    
    cout << "Search 15 after deletion: " << (search(root, 15) ? "Found" : "Not Found") << endl;
    
    cout << "\nDeleting 10\n";
    root = deleteKey(root, 10);
    cout << "Preorder after deletion: ";
    preorder(root);
    cout << endl;
    
    cout << "\nDeleting 30\n";
    root = deleteKey(root, 30);
    cout << "Preorder after deletion: ";
    preorder(root);
    cout << endl;
    
    cout << "\nTrying to delete non-existent 100\n";
    root = deleteKey(root, 100);
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    return 0;
}
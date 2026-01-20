#include<bits/stdc++.h>
using namespace std;

struct BSTreeNode{
    int data;
    BSTreeNode *left;
    BSTreeNode *right;

    BSTreeNode(int value){
        data= value;
        left = right = nullptr;
    }
};

BSTreeNode* createNode(int data){
    BSTreeNode *bst = new BSTreeNode(data);
    return bst;
}

BSTreeNode* insert(BSTreeNode *bst, int data){
    if(bst == nullptr){
        return createNode(data);
    }
    else if(data < bst->data){
        bst->left = insert(bst->left,data);
    }else{
       bst->right = insert(bst->right,data);
    }
    return bst;
}

bool search(BSTreeNode *bst , int key){
    if(bst == nullptr){
        return false;
    }

    if(bst->data == key){
        return true;
    }

    if(key < bst->data ){
        return search(bst->left,key);
    }
    return search(bst->right,key);
}

int main(){

    BSTreeNode *bst = createNode(50);
    insert(bst,40);
    insert(bst,60);
    insert(bst,30);
    insert(bst,45);
    insert(bst,55);
    insert(bst,70);

    bool flag = search(bst,50);
    if(flag){
        cout<< "found "<<endl;
    }
    else{
        cout<<"not found";
    }
}
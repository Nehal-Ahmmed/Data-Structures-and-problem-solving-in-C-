#include<bits/stdc++.h>
using namespace std;

struct BTreeNode{
    int data;
    BTreeNode *left;
    BTreeNode *right;

    BTreeNode(int d){
        data = d;
        left = right = nullptr;
    }
};

void preOrder(BTreeNode *bt){
    if(bt == nullptr){
        return;
    }
    cout<<bt->data<<" ";
    preOrder(bt->left);
    preOrder(bt->right);
}

void inOrder(BTreeNode *bt){
    if(bt == nullptr){
        return;
    }

    inOrder(bt->left);
    cout<<bt->data<<" ";
    inOrder(bt->right);
}

void postOrder(BTreeNode *bt){
    if(bt == nullptr){
        return;
    }

    postOrder(bt->left);
    postOrder(bt->right);
    cout<<bt->data<<" ";
}

int main(){
    
    BTreeNode *bt = new BTreeNode(10);
    bt->left = new BTreeNode(20);
    bt->right = new BTreeNode(30);
    bt->left->left = new BTreeNode(40);
    bt->left->right= new BTreeNode(50);

    cout<<"Pre order traversal: "<<endl;
    preOrder(bt);
    cout<<endl;
    cout<<"in order traversal: "<<endl;
    inOrder(bt);
    cout<<endl;
    cout<<"post order traversal: "<<endl;
    postOrder(bt);
}
#include <iostream>
#include <queue>
using namespace std;

// Basic Binary Tree Node Structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    inorder(root->left);        // Traverse left subtree
    cout << root->data << " ";  // Visit root
    inorder(root->right);       // Traverse right subtree
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    
    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    cout << root->data << " ";  // Visit root
}

int main() {
    // Create a sample binary tree
    // Structure:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    cout << "Preorder traversal (Root-Left-Right): ";
    preorder(root);
    cout << endl;
    
    cout << "Inorder traversal (Left-Root-Right): ";
    inorder(root);
    cout << endl;
    
    cout << "Postorder traversal (Left-Right-Root): ";
    postorder(root);
    cout << endl;
    
    // Clean up memory
    // Note: For simplicity, we're not writing full cleanup code here
    // In real program, write a function to delete all nodes
    
    return 0;
}


//

#include<bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int val){
        data = val;
        left = right = nullptr;
    }
};

BSTNode* createNode(int data){
    BSTNode* newNode = new BSTNode(data);
    return newNode;
}

BSTNode* insert(BSTNode *root, int data){
    if(root == nullptr){
        return createNode(data);
    }
    else if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(BSTNode *root, int key){
    if(root == nullptr){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main(){
    BSTNode *bst = nullptr;
    bst = insert(bst, 40);
    insert(bst, 60);
    insert(bst, 30);
    insert(bst, 45);
    insert(bst, 55);
    insert(bst, 70);

    bool flag = search(bst, 80);
    if(flag){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }
    
    return 0;
}
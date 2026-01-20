#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value){
        data = value;
        left = right = nullptr;
    }
};

TreeNode* createNode(int data){
    TreeNode *node = new TreeNode(data);
    return node;
}

TreeNode* createBinaryTree(){
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

void preorder(TreeNode *root){
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode *root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void preorderStack(TreeNode *root){
    if(root == nullptr) return;
    
    stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()){
        TreeNode *current = s.top();
        s.pop();
        cout << current->data << " ";
        
        if(current->right) s.push(current->right);
        if(current->left) s.push(current->left);
    }
}

void inorderStack(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode *current = root;
    
    while(current != nullptr || !s.empty()){
        while(current != nullptr){
            s.push(current);
            current = current->left;
        }
        
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void postorderStack(TreeNode *root){
    if(root == nullptr) return;
    
    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while(!s1.empty()){
        TreeNode *current = s1.top();
        s1.pop();
        s2.push(current);
        
        if(current->left) s1.push(current->left);
        if(current->right) s1.push(current->right);
    }
    
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

TreeNode* insertBST(TreeNode *bst, int data){
    if(bst == nullptr){
        return createNode(data);
    }
    else if(data < bst->data){
        bst->left = insertBST(bst->left, data);
    }
    else{
        bst->right = insertBST(bst->right, data);
    }
    return bst;
}

TreeNode* createBST(){
    TreeNode *bst = nullptr;
    bst = insertBST(bst, 50);
    bst = insertBST(bst, 30);
    bst = insertBST(bst, 70);
    bst = insertBST(bst, 20);
    bst = insertBST(bst, 40);
    bst = insertBST(bst, 60);
    bst = insertBST(bst, 80);
    return bst;
}

bool searchBST(TreeNode *bst, int key){
    if(bst == nullptr){
        return false;
    }
    if(bst->data == key){
        return true;
    }
    if(key < bst->data){
        return searchBST(bst->left, key);
    }
    return searchBST(bst->right, key);
}

TreeNode* findMin(TreeNode *root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

TreeNode* deleteBST(TreeNode *bst, int key){
    if(bst == nullptr) return bst;
    if(key < bst->data){
        bst->left = deleteBST(bst->left, key);
    }
    else if(key > bst->data){
        bst->right = deleteBST(bst->right, key);
    }
    else{
        if(bst->left == nullptr){
            TreeNode *temp = bst->right;
            delete bst;
            return temp;
        }
        else if(bst->right == nullptr){
            TreeNode *temp = bst->left;
            delete bst;
            return temp;
        }
        TreeNode *temp = findMin(bst->right);
        bst->data = temp->data;
        bst->right = deleteBST(bst->right, temp->data);
    }
    return bst;
}

int main(){
    
    cout << "Binary Tree Operations:" << endl;
    TreeNode *bt = createBinaryTree();
    cout << "Preorder using Recursive method: ";
    preorder(bt);
    cout << endl;

    cout << "Inorder using Recursive method: ";
    inorder(bt);
    cout << endl;
    
    cout << "Postorder using Recursive method: ";
    postorder(bt);
    cout << endl;
    
    cout << "Preorder using stack method: ";
    preorderStack(bt);
    cout << endl;
    
    cout << "Inorder using stack method: ";
    inorderStack(bt);
    cout << endl;
    
    cout << "Postorder using stack method: ";
    postorderStack(bt);
    cout << endl;
    
    cout << "\nBinary Search Tree Operations:" << endl;
    TreeNode *bst = createBST();
    
    cout << "BST Inorder: ";
    inorder(bst);
    cout << endl;
    cout << "Search 40: ";
    if(searchBST(bst, 40)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    
    cout << "Search 90: ";
    if(searchBST(bst, 90)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    
    cout << "Delete 40 from BST" << endl;
    bst = deleteBST(bst, 40);
    
    cout << "BST Inorder after deletion: ";
    inorder(bst);
    cout << endl;
    
    return 0;
}
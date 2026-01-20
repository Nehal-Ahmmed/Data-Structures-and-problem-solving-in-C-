#include <iostream>
#include <queue>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

// BST Node Structure
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Forward declarations
BSTNode* createNode(int value);
BSTNode* insert(BSTNode* root, int value);
bool search(BSTNode* root, int value);
BSTNode* findMin(BSTNode* root);
BSTNode* findMax(BSTNode* root);
BSTNode* deleteNode(BSTNode* root, int value);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);
void levelOrder(BSTNode* root);
int height(BSTNode* root);
int countNodes(BSTNode* root);
bool isBSTUtil(BSTNode* root, int min, int max);  // ADDED THIS DECLARATION
bool isBST(BSTNode* root);
BSTNode* findLCA(BSTNode* root, int n1, int n2);
void freeTree(BSTNode* root);

BSTNode* createNode(int value) {
    BSTNode* newNode = new BSTNode(value);
    return newNode;
}

BSTNode* insert(BSTNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

bool search(BSTNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    }
    
    if (value < root->data) {
        return search(root->left, value);
    }
    
    return search(root->right, value);
}

// 4. Find minimum value node
BSTNode* findMin(BSTNode* root) {
    if (root == nullptr) return nullptr;
    
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 5. Find maximum value node
BSTNode* findMax(BSTNode* root) {
    if (root == nullptr) return nullptr;
    
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// 6. Delete a node from BST
BSTNode* deleteNode(BSTNode* root, int value) {
    if (root == nullptr) return root;
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node found
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        else {
            BSTNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// 7. Tree Traversal Functions
void preorder(BSTNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BSTNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(BSTNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 8. Level Order Traversal
void levelOrder(BSTNode* root) {
    if (root == nullptr) return;
    
    queue<BSTNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        BSTNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

// 9. Find Height of Tree
int height(BSTNode* root) {
    if (root == nullptr) return -1;
    return max(height(root->left), height(root->right)) + 1;
}

// 10. Count Total Nodes
int countNodes(BSTNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 11. Helper function to check if tree is BST
bool isBSTUtil(BSTNode* root, int min, int max) {
    if (root == nullptr) return true;
    
    if (root->data <= min || root->data >= max) {
        return false;
    }
    
    return isBSTUtil(root->left, min, root->data) && 
           isBSTUtil(root->right, root->data, max);
}

// 12. Check if a Binary Tree is BST
bool isBST(BSTNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// 13. Find Lowest Common Ancestor (LCA)
BSTNode* findLCA(BSTNode* root, int n1, int n2) {
    if (root == nullptr) return nullptr;
    
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    
    return root;
}

// 14. Display Tree Structure

void displayTree(BSTNode* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    // Simple level-by-level display
    queue<BSTNode*> q;
    q.push(root);
    
    cout << "Tree Structure (Level Order):" << endl;
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            BSTNode* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }
}
// 15. Free Memory
void freeTree(BSTNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// 16. Print all traversals
void printTraversals(BSTNode* root) {
    cout << "\nTree Traversals:" << endl;
    cout << "Preorder:  ";
    preorder(root);
    cout << "\nInorder:   ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevelOrder:";
    levelOrder(root);
    cout << endl;
}

int main() {
    BSTNode* root = nullptr;
    
    // Create a sample BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Sample BST created!" << endl;
    
    // Test isBST
    if (isBST(root)) {
        cout << "✓ Tree is a valid BST!" << endl;
    } else {
        cout << "✗ Tree is NOT a valid BST!" << endl;
    }
    
    // Print inorder (should be sorted)
    cout << "Inorder traversal (should be sorted): ";
    inorder(root);
    cout << endl;
    
    // Test search
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not found") << endl;
    
    // Display tree structure
    cout << "\nTree Structure:" << endl;
    displayTree(root);
    
    // Free memory
    freeTree(root);
    
    return 0;
}
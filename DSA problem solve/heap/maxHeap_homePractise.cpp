#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
};

struct MinHeap {
    int* heap;
    int size;
    int capacity;
    HuffmanNode** huffmanHeap;
    int huffmanSize;
};

MinHeap createMinHeap(int capacity) {
    MinHeap h;
    h.heap = new int[capacity];
    h.size = 0;
    h.capacity = capacity;
    h.huffmanHeap = new HuffmanNode*[capacity];
    h.huffmanSize = 0;
    return h;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap& h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < h.size && h.heap[left] < h.heap[smallest])
        smallest = left;
    
    if (right < h.size && h.heap[right] < h.heap[smallest])
        smallest = right;
    
    if (smallest != idx) {
        swap(&h.heap[idx], &h.heap[smallest]);
        minHeapify(h, smallest);
    }
}

void buildMinHeap(MinHeap& h) {
    int n = h.size;
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(h, i);
}

void insertMinHeap(MinHeap& h, int val) {
    if (h.size == h.capacity) {
        cout << "Heap is full!" << endl;
        return;
    }
    
    h.size++;
    int i = h.size - 1;
    h.heap[i] = val;
    
    while (i != 0 && h.heap[(i - 1) / 2] > h.heap[i]) {
        swap(&h.heap[i], &h.heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool searchMinHeap(MinHeap& h, int val) {
    for (int i = 0; i < h.size; i++) {
        if (h.heap[i] == val)
            return true;
    }
    return false;
}

void deleteFromMinHeap(MinHeap& h, int val) {
    int idx = -1;
    
    for (int i = 0; i < h.size; i++) {
        if (h.heap[i] == val) {
            idx = i;
            break;
        }
    }
    
    if (idx == -1) {
        cout << "Value not found!" << endl;
        return;
    }
    
    h.heap[idx] = h.heap[h.size - 1];
    h.size--;
    minHeapify(h, idx);
}

void printMinHeap(MinHeap& h) {
    if (h.size == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }
    
    cout << "Min Heap: ";
    for (int i = 0; i < h.size; i++) {
        cout << h.heap[i] << " ";
    }
    cout << endl;
}

HuffmanNode* newHuffmanNode(char data, int freq) {
    HuffmanNode* node = new HuffmanNode;
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swapHuffmanNodes(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyHuffman(MinHeap& h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < h.huffmanSize && h.huffmanHeap[left]->freq < h.huffmanHeap[smallest]->freq)
        smallest = left;
    
    if (right < h.huffmanSize && h.huffmanHeap[right]->freq < h.huffmanHeap[smallest]->freq)
        smallest = right;
    
    if (smallest != idx) {
        swapHuffmanNodes(&h.huffmanHeap[idx], &h.huffmanHeap[smallest]);
        minHeapifyHuffman(h, smallest);
    }
}

void insertHuffmanHeap(MinHeap& h, HuffmanNode* node) {
    h.huffmanSize++;
    int i = h.huffmanSize - 1;
    h.huffmanHeap[i] = node;
    
    while (i != 0 && h.huffmanHeap[(i - 1) / 2]->freq > h.huffmanHeap[i]->freq) {
        swapHuffmanNodes(&h.huffmanHeap[i], &h.huffmanHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HuffmanNode* extractMinHuffman(MinHeap& h) {
    if (h.huffmanSize <= 0)
        return NULL;
    
    HuffmanNode* root = h.huffmanHeap[0];
    h.huffmanHeap[0] = h.huffmanHeap[h.huffmanSize - 1];
    h.huffmanSize--;
    minHeapifyHuffman(h, 0);
    
    return root;
}

void buildHuffmanHeap(MinHeap& h) {
    int n = h.huffmanSize - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapifyHuffman(h, i);
}

void printHuffmanCodes(HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        cout << root->data << ": ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}

void huffmanCoding(MinHeap& h, char data[], int freq[], int size) {
    for (int i = 0; i < size; i++) {
        h.huffmanHeap[i] = newHuffmanNode(data[i], freq[i]);
    }
    h.huffmanSize = size;
    
    buildHuffmanHeap(h);
    
    while (h.huffmanSize != 1) {
        HuffmanNode* left = extractMinHuffman(h);
        HuffmanNode* right = extractMinHuffman(h);
        
        HuffmanNode* top = newHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        insertHuffmanHeap(h, top);
    }
    
    HuffmanNode* root = extractMinHuffman(h);
    
    int arr[100];
    cout << "\nHuffman Codes:\n";
    printHuffmanCodes(root, arr, 0);
}
int main() {
    MinHeap h = createMinHeap(100);
    insertMinHeap(h, 5);
    insertMinHeap(h, 7);
    insertMinHeap(h, 9);
    insertMinHeap(h, 13);
    insertMinHeap(h, 15);
    insertMinHeap(h, 5);
    buildMinHeap(h);
    printMinHeap(h);
    
    insertMinHeap(h, 3);
    cout << "After inserting 3:" << endl;
    printMinHeap(h);
    
    cout << "Searching for 15: " << (searchMinHeap(h, 15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (searchMinHeap(h, 25) ? "Found" : "Not Found") << endl;
    
    deleteFromMinHeap(h, 15);
    cout << "After deleting 15:" << endl;
    printMinHeap(h);
    
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = 6;
    huffmanCoding(h, data, freq, size);
    
    return 0;
}
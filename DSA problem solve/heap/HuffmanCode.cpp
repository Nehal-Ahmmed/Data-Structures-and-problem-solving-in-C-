#include <bits/stdc++.h>
using namespace std;

struct minHeap
{
    int* heap;
    int size;
    int capacity;
};

struct huffNode
{
    char data;
    int freq;
    huffNode* left;
    huffNode* right;
    huffNode(char d, int f)
    {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

minHeap heapCreate(int c){
    minHeap head;
    head.heap = new int[c];
    head.size = 0;
    head.capacity = c;
    return head;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minifyHeap(minHeap &h, int idx){
    int smallest = idx;
    int left = 2 * idx +1;
    int right = 2 * idx +2;

    if(left < h.size && h.heap[left] < h.heap[smallest]){
        smallest = left;
    }

    if(right < h.size && h.heap[right] < h.heap[smallest]){
        smallest = right;
    }

    if(smallest != idx){
        swap(&h.heap[idx], &h.heap[smallest]);
        minifyHeap(h, smallest);
    }
}

void checking(minHeap &h){
    int n = h.size;
    for(int i = n/2 -1; i >=0; i--){
        minifyHeap(h, i);
    }
}

void insertInMinHeap(minHeap &head, int key){
    head.size++;
    int i = head.size - 1;
    head.heap[i] = key;

    while (i != 0 && head.heap[(i - 1) / 2] > head.heap[i]) {
        swap(&head.heap[i], &head.heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    checking(head);
}

void deleteInMinHeap(minHeap &h, int key){
    int i;
    for(i = 0; i < h.size; i++){
        if(h.heap[i] == key){
            break;
        }
    }
    if(i == h.size){
        cout << "Element not found in heap!" << endl;
        return;
    }

    h.heap[i] = h.heap[h.size - 1];
    h.size--;
    minifyHeap(h, i);
}

void printMinHeap(minHeap& h) {
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

void searchInMinHeap(minHeap &h, int key){
    for(int i = 0; i < h.size; i++){
        if(h.heap[i] == key){
            cout <<key<< " found in heap" << endl;
            return;
        }
    }
    cout <<key<< " not found in heap" << endl;
}

huffNode* huffNodes[100];
int huffCount = 0;

void addHuffNode(huffNode* node)
{
    huffNodes[huffCount] = node;
    huffCount++;
}

void sortHuffNodes()
{
    for(int i = 0; i < huffCount-1; i++)
    {
        for(int j = 0; j < huffCount-i-1; j++)
        {
            if(huffNodes[j]->freq > huffNodes[j+1]->freq)
            {
                huffNode* temp = huffNodes[j];
                huffNodes[j] = huffNodes[j+1];
                huffNodes[j+1] = temp;
            }
            else if(huffNodes[j]->freq == huffNodes[j+1]->freq && huffNodes[j]->data > huffNodes[j+1]->data)
            {
                huffNode* temp = huffNodes[j];
                huffNodes[j] = huffNodes[j+1];
                huffNodes[j+1] = temp;
            }
        }
    }
}

void removeFirstHuffNode()
{
    for(int i = 0; i < huffCount-1; i++)
    {
        huffNodes[i] = huffNodes[i+1];
    }
    huffCount--;
}

void printHuffCodes(huffNode* root, string code)
{
    if(!root) return;
    
    if(root->data != '$')
    {
        cout << root->data << " : " << code << endl;
    }
    
    printHuffCodes(root->left, code + "0");
    printHuffCodes(root->right, code + "1");
}

huffNode* buildHuffTree(string text)
{
    int freq[256] = {0};
    
    for(int i = 0; i < text.length(); i++)
    {
        freq[text[i]]++;
    }
    
    huffCount = 0;
    
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            addHuffNode(new huffNode((char)i, freq[i]));
        }
    }
    
    sortHuffNodes();
    
    while(huffCount > 1)
    {
        huffNode* left = huffNodes[0];
        removeFirstHuffNode();
        
        huffNode* right = huffNodes[0];
        removeFirstHuffNode();
        
        huffNode* top = new huffNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        addHuffNode(top);
        sortHuffNodes();
    }
    
    return huffNodes[0];
}

void huffmanEncode(string text)
{
    cout << "\nText: " << text << endl;
    
    huffNode* root = buildHuffTree(text);
    
    cout << "Huffman Codes:" << endl;
    printHuffCodes(root, "");
}

int main(){
    minHeap h = heapCreate(10);
    insertInMinHeap(h, 5);
    insertInMinHeap(h, 7);
    insertInMinHeap(h, 9);
    insertInMinHeap(h, 13);
    insertInMinHeap(h, 15);
    insertInMinHeap(h, 5);

    printMinHeap(h);

    deleteInMinHeap(h,7);

    printMinHeap(h);

    searchInMinHeap(h,13);
    searchInMinHeap(h,20);

    huffmanEncode("abracadabra");

    return 0;
}
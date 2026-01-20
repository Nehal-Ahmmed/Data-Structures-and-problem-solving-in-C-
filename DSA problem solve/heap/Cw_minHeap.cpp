#include <bits/stdc++.h>
using namespace std;

struct minHeap
{
    int* heap;
    int size;
    int capacity;
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

    return 0;
}


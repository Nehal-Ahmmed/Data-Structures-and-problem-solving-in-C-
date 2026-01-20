#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int criticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return 0;
    }
    
    int count = 0;
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* nextNode = head->next->next;
    
    while (nextNode) {
        if (curr->val > prev->val && curr->val > nextNode->val) {
            count++;
        }
        else if (curr->val < prev->val && curr->val < nextNode->val) {
            count++;
        }
        
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    
    return count;
}

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr1[] = {1,2,3,3,3,5,1,3};
    ListNode* head1 = createLinkedList(arr1, 8);
    cout << "Critical points in sample 1: " << criticalPoints(head1) << endl;
    
    int arr2[] = {1,2,3,2,1,3,2};
    ListNode* head2 = createLinkedList(arr2, 7);
    cout << "Critical points in sample 2: " << criticalPoints(head2) << endl;
    
    return 0;
}
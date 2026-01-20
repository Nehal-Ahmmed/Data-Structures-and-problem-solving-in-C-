#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int findMiddle(ListNode *head)
{
    if (!head)
        return -1;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    int t = 3;

    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = 5;

    int arr2[] = {10, 20, 30, 40};
    int n2 = 4;

    int arr3[] = {7};
    int n3 = 1;

    int* testArrays[] = {arr1, arr2, arr3};
    int sizes[] = {n1, n2, n3};

    for (int i = 0; i < t; i++)
    {
        ListNode *head = createLinkedList(testArrays[i], sizes[i]);
        cout << "Middle element of test case " << (i + 1) << ": ";
        cout << findMiddle(head) << endl;
    }

    return 0;
}

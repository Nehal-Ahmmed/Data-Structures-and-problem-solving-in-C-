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
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        int arr[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ListNode *head = createLinkedList(arr, n);
        cout << "Middle element: " << findMiddle(head) << endl;
    }

    return 0;
}
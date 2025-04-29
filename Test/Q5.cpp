#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *insert(Node *head, int val)
{
    if (!head)
        return new Node(val);
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
    return head;
}

int findMiddle(Node *head)
{
    if (!head)
        return -1;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, val;
        cin >> n;
        Node *head = nullptr;
        for (int i = 0; i < n; ++i)
        {
            cin >> val;
            head = insert(head, val);
        }
        cout << findMiddle(head) << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
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

Node *mergeLists(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->data > b->data)
        swap(a, b);

    Node *res = a;

    while (a && b)
    {
        Node *tmp = nullptr;
        while (a && a->data <= b->data)
        {
            tmp = a;
            a = a->next;
        }
        tmp->next = b;
        swap(a, b);
    }
    return res;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, val;
        cin >> n >> m;

        Node *head1 = NULL;
        for (int i = 0; i < n; ++i)
        {
            cin >> val;
            head1 = insert(head1, val);
        }

        Node *head2 = NULL;
        for (int i = 0; i < m; ++i)
        {
            cin >> val;
            head2 = insert(head2, val);
        }

        Node *merged = mergeLists(head1, head2);
        printList(merged);
    }
    return 0;
}
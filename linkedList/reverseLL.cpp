#include <bits/stdc++.h>
using namespace std;
//reverse a linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *reverseLL(Node *head) // time complexity O(n) and space complexity O(1)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *ford = NULL;
    while (curr != NULL)
    {
        ford = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ford;
    }
    return prev;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node *ans = reverseLL(head);
    Node *temp = ans;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
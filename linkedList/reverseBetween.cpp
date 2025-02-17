#include<bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
// Reverse a linked list from position m to n. Do it in one-pass.
ListNode *reverseBetween(ListNode *head, int left, int right) // Time complexity O(n) and space complexity O(1)
{
    if (head == NULL || left == right)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    // Move `prev` to the node before the `left` position
    for (int i = 0; i < left - 1; i++)
    {
        prev = prev->next;
    }

    ListNode *curr = prev->next;
    ListNode *prevNode = NULL;
    ListNode *nextNode = NULL;

    for (int i = 0; i <= right - left; i++)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    prev->next->next = curr;
    prev->next = prevNode;
    return dummy->next;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2;
    int right = 4;
    ListNode* result = reverseBetween(head,left,right);
    while(result!=NULL){
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};
// You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) // O(n) time complexity and O(n) space complexity
{
    int carry = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
    }
    return dummy->next;
}
int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* ans = addTwoNumbers(l1, l2);
    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}
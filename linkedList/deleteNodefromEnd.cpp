#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        count -= n;
        if (count == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (count--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution obj;
    ListNode* res = obj.removeNthFromEnd(head, 2);
    cout << "Resultant linked list: ";
    while(res != NULL){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
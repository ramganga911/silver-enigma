#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node != NULL && node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete(node);
    }
};
int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    Solution obj;
    obj.deleteNode(head->next);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* first = head;
        ListNode* sec = head->next;
        
        ListNode* prev = NULL;

        while(first!= NULL && sec!= NULL){
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
            if(prev!= NULL){
                prev->next = sec;
            }else{
                head= sec;
            }

            //update
            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            }else{
                sec = NULL;
            }
        }
        return head;
    }
};
int main(){
    Solution obj;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = obj.swapPairs(head);
    cout << "Resultant linked list: ";
    while(res != NULL){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
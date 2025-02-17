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
// Rotate List by k places
ListNode* rotateList(ListNode* head,int k){ // Time complexity O(n) and space complexity O(1)
    if(head==NULL || k==0 || head->next == NULL) return head;
    int count =0;
    ListNode* temp = head;
    while(temp!=NULL){
        count++;
        temp= temp->next;
    }
    k%=count;
    if (count == 0)
        return head;
    count -= k;
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    ListNode* tail = curr;
    while(tail->next){
        tail = tail->next;
    }
    tail->next = head;
    head = curr;
    return head;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    ListNode* result = rotateList(head,k);
    while(result!=NULL){
        cout << result->data << " ";
        result = result->next;
    }
    return 0;
}
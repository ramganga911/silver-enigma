#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
//find the starting point of the cycle and remove the cycle from the linked list
Node* findCycleAndRemove(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast){
        return head;
    }
    slow = head;
    Node* prev = NULL;
    while(slow != fast){
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;
    Node* ans = findCycleAndRemove(head);
    cout <<"Starting point of the cycle is: "<<ans->data;
    return 0;
}
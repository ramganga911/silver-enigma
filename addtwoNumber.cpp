#include<bits/stdc++.h>
using namespace std;
// Add two numbers represented by linked list
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* addTwoNumbers(Node *l1, Node *l2) // O(n) time complexity
{
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry =0;
    while(l1!= NULL || l2!= NULL ||carry){
        int sum = carry;
        if(l1!=NULL){
            sum += l1->data;
            l1= l1->next;
        }
        if(l2!= NULL){
            sum+= l2->data;
            l2 = l2->next;
        }
        carry = sum/10;
        Node* newNode = new Node(sum%10);
        temp->next = newNode;
        temp= temp->next;
    }
    return dummy->next;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);
    Node* ans = addTwoNumbers(head1, head2);
    printList(ans);
    return 0;
}
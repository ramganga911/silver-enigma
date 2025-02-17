#include<bits/stdc++.h>
using namespace std;
// Delete the nth node from the end of the linked list
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
Node* deleteNthNode(Node* head,int n){ // Time complexity O(n) and Space complexity O(1)
    if(head == NULL) return head;
    Node* temp= head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp= temp->next;
    }
    count -=n;
    if(count ==0){
        Node* temp=head;
        head= head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;

    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        cout << temp->data<< "->";
        temp=temp->next;
    }cout << temp->data;
}
int main(){
    Node* head= new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int n= 2;
    deleteNthNode(head,2);
    print(head);
    return 0;
}
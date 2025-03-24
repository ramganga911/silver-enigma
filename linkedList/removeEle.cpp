#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* removeEle(Node* head, int val){
    if(head==NULL || head->next == NULL) return head;
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* tail = dummy;
    
    while(tail!= NULL && tail->next != NULL){
        if(tail->next->data == val){
            Node* temp = tail->next;
            tail->next = temp->next;
            delete(temp);
        }else{
            tail = tail->next;
        }
    }
    return dummy->next;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(1);
    cout << "Original List: ";
    printLL(head);
    cout << endl;
    Node *ans = removeEle(head, 1);

    cout << "Updated List: ";
    printLL(ans);
}
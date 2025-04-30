#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
    }
};
Node* insert(Node* head, int val){
    if(!head){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}
void printReverse(Node* head){
    if(!head){
        return;
    }
    printReverse(head->next);
    cout<< head->data<<" ";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n, val;
        cin>> n;
        Node* head = NULL;
        for(int i=0; i<n; i++){
            cin>>val;
            head = insert(head, val);
        }
        printReverse(head);
        cout << endl;
    }
    return 0;
}
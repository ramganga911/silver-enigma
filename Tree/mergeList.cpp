#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* insert(Node* head , int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}
Node* mergeLists(Node*a, Node*b){
    if (!a)
    {
        return b;
    }
    if(!b){
        return a;
    }
    if(a->data>b->data){
        swap(a,b);
    }
    Node* res = a;
    while(a&&b){
        Node* temp = NULL;
        while(a && a->data <= b->data){
            temp = a;
            a = a->next;
        }
        temp->next = b;
        swap(a,b);
    }
    return res;
}
void Print(Node* head){
    Node* temp =head;
    while(temp){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m, val;
        cin>>n>>m;
        Node* head1 = NULL;
        for(int i=0; i<n; i++){
            cin>> val;
            head1 = insert(head1, val);
        }
        Node* head2 = NULL;
        for(int j=0; j<m; j++){
            cin>> val;
            head2 = insert(head2, val);
        }
        Node* merged = mergeLists(head1, head2);
        Print(merged);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right  = NULL;
    }
};
static int idx =-1;
Node* BuildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    Node* root = new Node(preorder[idx]);
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);
    return root;
}
// void preOrder(Node* root){
//     if(root == NULL){
//         return;
//     }
//     cout << root->data << " ";
//     preOrder(root->left);
//     preOrder(root->right);   
// }
void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight,rightheight)+1; 
}
int countNode(Node* root){
    if(root==NULL)return 0;
    int leftNode = countNode(root->left);
    int rightNode = countNode(root->right);
    return leftNode+rightNode+1;
}
int sumofNode(Node* root){
    if(root == NULL) return 0;
    int leftSum = sumofNode(root->left);
    int rightSum = sumofNode(root->right);
    return leftSum+rightSum+root->data;
}
bool isIdentical(Node*p, Node*q){
    if(p==NULL && q!=NULL) return false;
    if(p!=NULL && q==NULL) return false;
    if(p==NULL && q==NULL) return true;
    bool isleftSame = isIdentical(p->left, q->left);
    bool isRightSame = isIdentical(p->right,q->right);
    return isleftSame&& isRightSame && (p->data == q->data);
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(preorder);
    Node *p = BuildTree(preorder);
    Node *q = BuildTree(preorder);
    // preOrder(root);
    levelOrder(root);
    cout << height(root)<<endl;
    cout << countNode(root)<<endl;
    cout << sumofNode(root)<< endl;
    cout << isIdentical(p, q);
    return 0;
}
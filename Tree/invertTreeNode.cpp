#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// Invert a binary tree
TreeNode* invertTreeNode(TreeNode* root){ // Time complexity O(n) and space complexity O(n)
    if(!root) return NULL;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        swap(node->left, node->right);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}
void printTree(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    printTree(root); cout << endl;
    invertTreeNode(root);
    printTree(root);
    return 0;
}
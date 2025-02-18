#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// Lowest Common Ancestor of a Binary Tree
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){ // Time complexity O(n) and space complexity O(n)
    if(root == NULL) return nullptr;
    if(root == p || root == q) return root;
    TreeNode* left = lca(root->left,p,q);
    TreeNode* right = lca(root->right,p,q);
    if(left == NULL) return right;
    if(right == NULL) return left; 
    return root;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(0);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* result = lca(root,p,q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << result->val;
    return 0;
}
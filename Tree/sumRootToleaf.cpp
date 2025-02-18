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
// Sum of Root to Leaf Binary Numbers
int dfs(TreeNode* root,int currentNumber){ // Time complexity O(n) and space complexity O(n)
    if(!root) return 0;
    currentNumber = currentNumber*10 + root->val;
    if(!root->left && !root->right) return currentNumber;
    return dfs(root->left,currentNumber)+dfs(root->right, currentNumber);
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << dfs(root,0);
    return 0;
}
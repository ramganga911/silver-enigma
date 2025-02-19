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
// Right View of Binary Tree
vector<int> rightSideView(TreeNode* root){ // Time complexity O(n) and space complexity O(n)
    if(!root) return {};
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* rightMostNode = NULL;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* node = q.front();
            q.pop();
            rightMostNode = node;
            if(node->left) q.push(node->left);  
            if(node->right) q.push(node->right);
        }
        result.push_back(rightMostNode->val);
    }
    return result;
}
void print(TreeNode* root){
    vector<int> result  = rightSideView(root);
    for(auto x: result){
        cout << x << " ";
    }
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    print(root);
    return 0;
}
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
// Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root){ // Time complexity O(n) and space complexity O(n)
    vector<vector<int>> result;
    if(root == NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> ans;
        while(size--){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        result.push_back(ans);
    }
    return result;
}
void print(TreeNode* root){
    vector<vector<int>> result = levelOrder(root);
    for(auto x: result){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    print(root);

    return 0;
}
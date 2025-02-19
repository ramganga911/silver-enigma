#include <bits/stdc++.h>
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
// Zig Zag Level Order Traversal
vector<vector<int>> levelOrder(TreeNode *root)
{ // Time complexity O(n) and space complexity O(n)
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            TreeNode* node = q.front();
            q.pop();
            int index = flag ? i : n-i-1;
            ans[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        flag =  !flag;
        result.push_back(ans);
    }
    return result;
}
void print(TreeNode *root)
{
    vector<vector<int>> result = levelOrder(root);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
int main()
{
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
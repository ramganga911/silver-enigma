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
// Average of Levels in Binary Tree
vector<double> averageOfLevels(TreeNode *root) // Time complexity O(n) and space complexity O(n)
{
    vector<double> avg;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        double sum = 0;
        double count = n;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            sum += temp->val;
        }
        avg.push_back(sum / count);
    }
    return avg;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<double> result = averageOfLevels(root);
    for(auto x: result){
        cout << x << " ";
    }
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void reverseInorder(TreeNode *root, int k, int &count, int &ans)
{
    if (!root || count >= k)
        return;

    reverseInorder(root->right, k, count, ans);
    count++;
    if (count == k)
    {
        ans = root->val;
        return;
    }
    reverseInorder(root->left, k, count, ans);
}

int findKthLargest(TreeNode *root, int k)
{
    int count = 0, ans = -1;
    reverseInorder(root, k, count, ans);
    return ans;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nodes[i];
        }
        int k;
        cin >> k;

        TreeNode *root = buildTree(nodes);
        cout << findKthLargest(root, k) << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* BuildTree(vector<int>&list){
    if(list.size()==0||list[0]==-1) return NULL;
    Node* root = new Node(list[0]);
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<list.size()){
        Node* curr = q.front();
        q.pop();
        if(i<list.size()&& list[i]!=-1){
            curr->left = new Node(list[i]);
            q.push(curr->left);
        }
        i++;
        if(i<list.size()&& list[i]!=-1){
            curr->right = new Node( list[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
void solve(Node *root, int k, int &count, int &ans)
{
    if (root == NULL)
        return;
    solve(root->right, k, count, ans);
    if (k == count)
    {
        ans = root->data;
        count++;
        return;
    }
    else
        count++;
    solve(root->left, k, count, ans);
}
int kthLargest(Node *root, int k)
{
    // Your code here
    int count = 1;
    int ans = -1;
    solve(root, k, count, ans);
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        BuildTree(vec);
        int k;
        cin>>k;
        Node* root = BuildTree(vec);
        cout << kthLargest(root,k);
    }
    return 0;
}
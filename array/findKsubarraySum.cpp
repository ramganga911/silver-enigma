#include <bits/stdc++.h>
using namespace std;
vector<int> ksubarrysum(int arr[], int k, int n)
{
    vector<int> ans;
    if (k > n)
        return ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans.push_back(sum);
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        ans.push_back(sum);
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> ans = ksubarrysum(arr, k, n);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
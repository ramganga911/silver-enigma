#include <bits/stdc++.h>
using namespace std;
// Combination Sum I
set<vector<int>> s;
void solve(vector<int> &nums, int idx, int target, vector<int> &ans, vector<vector<int>> &result) // Time complexity O(2^n) and space complexity O(n)
{
    if (idx == nums.size() || target < 0)
    {
        return;
    }
    if (target == 0)
    {
        if (s.find(ans) == s.end())
        {
            result.push_back(ans);
            s.insert(ans);
        }
    }
    ans.push_back(nums[idx]);
    solve(nums, idx, target - nums[idx], ans, result);
    ans.pop_back();
    solve(nums, idx + 1, target, ans, result);
}
{
    if (idx == nums.size() || target < 0)
    {
        return;
    }
    if (target == 0)
    {
        if (s.find(ans) == s.end())
        {
            result.push_back(ans);
            s.insert(ans);
        }
    }
    ans.push_back(nums[idx]);
    // single time include
    solve(nums, idx + 1, target - nums[idx], ans, result);
    // multiple time include
    solve(nums, idx, target - nums[idx], ans, result);
    ans.pop_back();
    solve(nums, idx + 1, target, ans, result);
}
int main()
{
    vector<int> nums = {2, 3, 5};
    vector<int> ans;
    vector<vector<int>> result;
    int target = 8;
    solve(nums, 0, target, ans, result);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
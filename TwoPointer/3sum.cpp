#include <bits/stdc++.h>
using namespace std;
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
vector<int> find3Sum(vector<int> &nums, int target) // Time complexity O(n^2) and space complexity O(1)
{
    int n = nums.size();
    vector<int> result;
    if (n < 2)
        return result;
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int remaining = target - nums[i]; // remaining sum
        int j = i + 1;
        int k = n - 1;
        while (j < k && nums[j] == nums[j - 1]) // remove duplicates
        {
            j++;
        }
        while (k > 0 && nums[k] == nums[k + 1]) // remove duplicates
        {
            k--;
        }
        while (j < k)
        {
            int sum = nums[j] + nums[k];
            if (sum == remaining)
            {
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                result.push_back(nums[k]);
                return result;
            }
            else if (sum < remaining)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    vector<int> ans = find3Sum(nums, target);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
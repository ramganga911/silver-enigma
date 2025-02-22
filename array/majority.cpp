#include <bits/stdc++.h>
using namespace std;
// Majority element n/2
// int majorityElement(vector<int> &nums, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; i++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 count++;
//             }
//         }
//         if (count > n / 2)
//         {
//             return nums[i];
//         }
//     }
//     return -1;
// }
// int majorityElement(vector<int>&nums,int n){
//     unordered_map<int,int>mp;
//     for(int i=0; i<n; i++){
//         mp[nums[i]]++;
//         if(mp[nums[i]]>n/2){
//             return nums[i];
//         }
//     }
//     return -1;
// }
// Moore's Voting Algorithm
int majorityElement(vector<int> &nums, int n) // Time complexity O(n) and space complexity O(1)
{
    int candidate = nums[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (candidate == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return candidate;
    }
    return -1;
}
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();
    int ans = majorityElement(nums, n);
    cout << "Majority element is: " << ans;
    return 0;
}
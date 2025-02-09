#include <bits/stdc++.h>
using namespace std;
// vector<int> findTwoSum(vector<int>&nums, int target){ // O(nlogn) time complexity
//     if(nums.size() == 0){
//         return {};
//     }
//     sort(nums.begin(), nums.end());
//     vector<int> ans;
//     int i=0,j= nums.size()-1;
//     while(i<j){
//         if(nums[i]+nums[j]==target){
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }else if(nums[i]+nums[j]<target){
//             i++;
//         }else{
//             j--;
//         }
//     }
//     return ans;
// }
vector<int> findTwoSum(vector<int> &nums, int target)
{ // O(n) time complexity
    if (nums.size() == 0)
    {
        return {};
    }
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = target - nums[i];
        if (mp.find(sum) != mp.end())
        {
            ans.push_back(mp[sum]);
            ans.push_back(i);
            break;
        }
        mp[nums[i]] = i;
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans;
    ans = findTwoSum(nums, target);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
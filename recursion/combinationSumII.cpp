#include<bits/stdc++.h>
using namespace std;
// Combination Sum II
void solve(vector<int>&nums, int idx, int target, vector<int>&ans, vector<vector<int>>&result){ // Time complexity O(2^n) and space complexity O(n)
    if(target<0) return;
    if(target==0){
        result.push_back(ans);
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        if(i>idx && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        ans.push_back(nums[i]);
        solve(nums,i+1, target-nums[i], ans, result);
        ans.pop_back();
    }
}
int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> ans;
    solve(nums, 0, target, ans, result);
    cout << "Combinations sum are: " << endl;
    for(auto x : result){
        for(auto y: x){
            cout << y<<" ";
        }cout << endl;
    }
    return 0;
}
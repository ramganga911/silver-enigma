#include<bits/stdc++.h>
using namespace std;
// Two Sum of an array
vector<int> findTwoSum(vector<int>& nums, int target){ // Time complexity O(n) and space complexity O(n)
    int n = nums.size();  
    unordered_map<int,int> mp;
    vector<int> result;
    for(int i=0; i<n; i++){
        int remaining = target - nums[i];
        if(mp.find(remaining)!= mp.end()){
            result.push_back(mp[remaining]);
            result.push_back(i);
            break;
        }
        mp[nums[i]] = i;
    }
    return result;
}
int main(){
    vector<int>nums= {1,2,3,4,3};
    int target = 7;
    vector<int> ans = findTwoSum(nums, target);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}
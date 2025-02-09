#include<bits/stdc++.h>
using namespace std;
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
vector<int> findTwoSum(vector<int>& nums, int target){ // O(n) time complexity and O(n) space complexity
    unordered_map<int, int> map;
    vector<int> result;
    for(int i=0; i<nums.size(); i++){
        int diff = target - nums[i];
        if(map.find(diff) != map.end()){
            result.push_back(map[diff]);
            result.push_back(i);
            return result;
        }
        map[nums[i]] = i;
    }
    return result;
}
int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result;
    result = findTwoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
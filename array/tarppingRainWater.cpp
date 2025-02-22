#include<bits/stdc++.h>
using namespace std;
// Trap rain water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
int trappingRainWater(vector<int>&nums){ // Time complexity: O(n) and Space complexity: O(n)
    int n = nums.size();
    vector<int> left(n,-1);
    vector<int>right(n,-1);
    left[0] = nums[0];
    right[n-1] = nums[n-1];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], nums[i]);
    }
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], nums[i]);
    }
    int result=0;
    for(int i=1; i<n-1; i++){
        int minOf2 = min(left[i-1],right[i+1]);
        if(minOf2> nums[i]){
            result+= minOf2- nums[i];
        }
    }
    return  result;
}
int main(){
    vector<int> nums = {2, 1, 5, 3, 1, 0, 4};
    int ans = trappingRainWater(nums);
    cout <<"Trapping rain water are : " <<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Kth largest element
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Example:
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
int kthLargestEle(vector<int>&nums, int k){ // Time complexity: O(nlogk) and Space complexity: O(k)
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<k; i++){
        pq.push(nums[i]);
    }
    for(int i=k; i<nums.size(); i++){
        if(nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main(){
    vector<int> nums  = {3,2,1,5,6,4};
    int k =2;
    int ans = kthLargestEle(nums,k);
    cout << "Kth largest element is : " << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Maximum Subarray
int maximumSubarray(vector<int>& nums){ // Time complexity O(n) and space complexity O(1)
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum =0; 
    for(int i=0; i<n; i++){
        sum+= nums[i];
        maxSum = max(maxSum, sum);
        if(sum<0){
            sum =0;
        }
    }
    return maxSum;
}
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maximumSubarray(nums);
    cout << "Maximum sum of subarray is: " << ans;
    return 0;
}
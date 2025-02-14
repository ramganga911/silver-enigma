#include<bits/stdc++.h>
using namespace std;
// Minimum Size Subarray Sum
int findMinSubarray(vector<int> &nums, int target){ // Time complexity O(n) and space complexity O(1)
    int n = nums.size();
    int left =0;
    int minLen = INT_MAX;
    int sum=0;
    for(int right =0; right <n; right++){
        sum+=nums[right]; // add the current element to the sum ,Expand the window
        while(sum>= target){ // if the sum is greater than the target then shrink the window
            minLen = min(minLen, right-left+1);
            sum-= nums[left];
            left++;
        }
    }
    return (minLen==INT_MAX?0:minLen);
}
int main(){
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int minLen = findMinSubarray(arr, target);
    cout << "Minimum Subarray Sum length: " << minLen;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// maximum subarray sum
vector<int> printMaxSubarray(vector<int>&nums){
    int n = nums.size();
    int resStart =0;
    int resEnd = 0;
    int maxSum = nums[0];
    for(int i=0; i<n; i++){
        int cumSum =0;
        for(int j=i; j<n; j++){
            cumSum+=nums[j];
            if(cumSum>maxSum){
                maxSum = cumSum;
                resStart = i;
                resEnd = j;
            }
        }
    }
    vector<int> result;
    for(int i=resStart; i<= resEnd; i++){
        result.push_back(nums[i]);
    }
    return result;
}
// kadane's algorithm
int maximumSubarray(vector<int> &nums) // Time complexity O(n) and space complexity O(1)
{
    int n = nums.size();
    int maxSum = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(sum + nums[i], nums[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();
    int ans = maximumSubarray(nums);
    cout << "Maximum sum of subarray is: " << ans;
    cout << endl;
    vector<int> result = printMaxSubarray(nums);
    for(auto x: result){
        cout << x << " ";
    }
    return 0;
}
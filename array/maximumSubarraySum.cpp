#include <bits/stdc++.h>
using namespace std;
// maximum subarray sum
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
    return 0;
}
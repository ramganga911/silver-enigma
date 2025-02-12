#include <bits/stdc++.h>
using namespace std;
// Rotate Array by k
void reverse(vector<int> &nums, int start, int end) // Time complexity O(n) and space complexity O(1)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1); // Time complexity O(n) and space complexity O(1)
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}
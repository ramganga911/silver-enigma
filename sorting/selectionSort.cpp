#include <bits/stdc++.h>
using namespace std;
// Selection sort
// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
// The algorithm maintains two subarrays in a given array.
void selectionSort(vector<int> &nums, int n) // Time complexity: O(n^2) and Space complexity: O(1)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}
int main()
{
    vector<int> nums = {2, 1, 5, 3, 1, 0, 4};
    int n = nums.size();
    selectionSort(nums, n);
    for (int it : nums)
    {
        cout << it << " ";
    }
    return 0;
}
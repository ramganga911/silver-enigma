#include <bits/stdc++.h>
using namespace std;
// Merge sort
// Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
// The merge() function is used for merging two halves. 
void merge(vector<int> &nums, int left, int mid, int right) // Time complexity: O(nlogn) and Space complexity: O(n)
{
    int i = left, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= right)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int i = left; i <= right; i++)
    {
        nums[i] = temp[i - left];
    }
}

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}
int main()
{
    vector<int> nums = {2, 1, 5, 3, 1, 0, 4};
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    cout << "Sorted array is : " << endl;
    for (int it : nums)
    {
        cout << it << " ";
    }
    return 0;
}
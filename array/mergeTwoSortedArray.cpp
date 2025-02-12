#include <bits/stdc++.h>
using namespace std;
// Merge two sorted arrays without using extra space
void mergeTwoArray(vector<int> &arr1, vector<int> &arr2) // Time complexity O(n+m) and space complexity O(1)
{
    int n = arr1.size() - arr2.size(); // actual size of arr1
    int m = arr2.size();
    arr1.resize(n + m);
    int i = n - 1, j = m - 1, k = n + m - 1;
    while (j >= 0)
    {
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            k--;
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            k--;
            j--;
        }

    }
}
int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 5, 6};
    arr1.resize(arr1.size()+arr2.size());
    mergeTwoArray(arr1, arr2);
    for (int i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}
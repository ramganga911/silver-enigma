#include <bits/stdc++.h>
using namespace std;
// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
int main()
{
    vector<int> arr = {1, 2, 3, 3, 5, 5}; // time complexity O(n) and space complexity O(1)
    int n = arr.size();
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    cout << i + 1;

    return 0;
}
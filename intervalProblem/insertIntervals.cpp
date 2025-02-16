#include <bits/stdc++.h>
using namespace std;
// Insert Intervals
vector<vector<int>> insertIntervals(vector<vector<int>> &intervals, vector<int> &newIntervals) // Time complexity O(n) and space complexity O(n)
{
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> result;
    while (i < n)
    {
        if (intervals[i][1] < newIntervals[0])
        {
            result.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newIntervals[1])
        {
            break;
        }
        else
        {
            newIntervals[0] = min(intervals[i][0], newIntervals[0]);
            newIntervals[1] = max(intervals[i][1], newIntervals[1]);
        }
        i++;
    }
    result.push_back(newIntervals);
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}
int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {15, 18}};
    vector<int> newIntervals = {4, 8};
    vector<vector<int>> result = insertIntervals(intervals, newIntervals);
    for (auto it : result)
    {
        for (int i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
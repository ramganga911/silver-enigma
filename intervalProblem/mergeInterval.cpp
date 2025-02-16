#include <bits/stdc++.h>
using namespace std;
// merge intervals 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) // time complexity O(nlogn) and space complexity O(n)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    int n = intervals.size();
    if (n == 0)
        return result;
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> &last = result.back();
        vector<int> &curr = intervals[i];

        if (last[1] >= curr[0])
        {
            last[1] = max(curr[1], last[1]);
        }
        else
        {
            result.push_back(curr);
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = mergeIntervals(intervals);
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
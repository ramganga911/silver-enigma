#include <bits/stdc++.h>
using namespace std;
// Generate Parentheses
vector<string> result;
void solve(int n, int left, int right, string &curr) // Time complexity O(2^n) and space complexity O(n)
{
    if (curr.size() == 2 * n)
    {
        result.push_back(curr);
        return;
    }
    if (left < n)
    {
        curr.push_back('(');
        solve(n, left + 1, right, curr);
        curr.pop_back();
    }
    if (left > right && right < n)
    {
        curr.push_back(')');
        solve(n, left, right + 1, curr);
        curr.pop_back();
    }
}
int main()
{
    int n = 3;
    string curr = "";
    int left = 0, right = 0;
    solve(n, left, right, curr);
    cout << "All possible combinations of parenthesis are: " << endl;
    for (auto x : result)
    {
        cout << x << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// Is Subsequence s is a subsequence of t
bool check(string s, string t) // Time complexity O(n) and space complexity O(1)
{
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    return i == n;
}
int main()
{
    string s = "abc";
    string t = "ahbgdc";
    bool isSubsequence = check(s, t);
    if (isSubsequence)
    {
        cout << "Is Subsequence";
    }
    else
    {
        cout << "Not a Subsequence";
    }
    return 0;
}
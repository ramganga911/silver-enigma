#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char ch : s)
        {
            mp[ch]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode")<<endl;
    cout<<s.firstUniqChar("loveleetcode")<<endl;
    return 0;
}
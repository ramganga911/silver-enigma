#include<bits/stdc++.h>
using namespace std;
// Longest Substring Without Repeating Characters
int LongestSubstringWithoutRepeatingChar(string s){ // Time complexity O(n) and space complexity O(n)
    int n = s.size();
    string result ="";
    unordered_map<char,int>seen;
    int i=0,j=0;
    int maxLen =0;
    while(j<n){
        char curr = s[j];
        if(seen.count(curr)==1&& seen[curr]>=i){
            i = seen[curr]+1;
        }else{
            seen[curr]=j;
            j++;
        }
        if((j-i)> maxLen){
            maxLen = j-i;
            result = s.substr(i, j-i);
        }
    }
    cout << "Substring without repeating char: " << result << endl;
    return maxLen;
}
int main(){
    string s = "abcabcbb";
    int ans = LongestSubstringWithoutRepeatingChar(s);
    cout << "Max Length of Substring without repeating char: " << ans;
    return 0;
}
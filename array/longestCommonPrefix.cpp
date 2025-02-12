#include<bits/stdc++.h>
using namespace std;
// find Longest Common Prefix
string findLongestCommonPrefix(vector<string>s){ // Time complexity O(n*m) and space complexity O(1)
    int n = s.size();
    string check ="";
    int minLen = INT_MAX;
    for(int i=0; i<n; i++){
        if(s[i].size() <= minLen){
            minLen = s[i].size();
            check = s[i];
        }
    }
    string prefix ="";
    for(int i=0; i<minLen; i++){ // Time complexity O(n*m) and space complexity O(1)
        for(int j=0; j<n; j++){
            if(s[j][i] != check[i]){
                return prefix;
            }
        }
        prefix += check[i];
    }
    return prefix;
}
int main(){
    vector<string> s = {"flower","flow","flight"};
    string ans = findLongestCommonPrefix(s);
    cout << "Length of the longest common prefix is: "<<ans;
    return 0;
}
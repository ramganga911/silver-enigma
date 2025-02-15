#include<bits/stdc++.h>
using namespace std;
// Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs){ // Time complexity O(n*mlogm) and space complexity O(n)
    unordered_map<string, vector<string>> mp;
    for(string str: strs){
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(str);
    }
    vector<vector<string>> result;
    for(auto it: mp){
        result.push_back(it.second);
    }
    return result;
}
int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for(auto vec: result){
        for(string str: vec){
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
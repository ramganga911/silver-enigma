#include<bits/stdc++.h>
using namespace std;
// Find Combinations
void solve(int start, int n, int k, vector<vector<int>>&result, vector<int>&ans){ // Time complexity O(n^k) and space complexity O(n)
    if(ans.size()==k){
        result.push_back(ans);
        return;
    }
    for(int i=start; i<=n; i++){
        ans.push_back(i); // include the current element
        solve(i+1,n,k, result, ans); // recursively find the next element
        ans.pop_back(); // backtrack
    }
}
int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> result;
    vector<int> ans;
    solve(1,n,k, result, ans);
    for(auto x : result){
        for(auto y: x){
            cout << y<< " ";
        }cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool check(int start, vector<int>&nums){
    int n = nums.size();
    unordered_set<int> st;
    for(int j=start; j<n; j++){
        if(st.count(nums[j])){
            return false;
        }
        st.insert(nums[j]);
    }
    return true;
}
// int solve(vector<int>&arr){ // TimeCopmlexity O(n^2) and Space Complexity O(n)
//     int n = arr.size();
//     int op = 0;
//     for(int i=0; i<n; i+=3){
//         if(check(i,arr)==true){
//             return op;
//         }
//         op++;
//     }
//     return op;
// }
int solve(vector<int>&arr){ // TimeComplexity O(n) and SpaceComplexity O(n)
    int n = arr.size(); 
    unordered_set<int> st;
    for(int i=n-1; i>=0; i--){
        if(st.count(arr[i])){
            return ceil((i+1)/3.0);
        }
        st.insert(arr[i]);
    }
    return 0;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    int ans = solve(arr);
    cout << "Minimum Number of Operation to make array distinct: "<< ans<<endl;
    return 0;
}
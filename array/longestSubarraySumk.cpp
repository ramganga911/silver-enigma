#include<bits/stdc++.h>
using namespace std;
// This work only for positive array
// int longestSubarraySumK(vector<int>&arr, int K){
//     int n = arr.size();
//     int sum = 0;
//     int i=0,j=0;
//     int maxLen =0;
//     unordered_map<int,int>mp;
//     while(j<n){
//         sum+=arr[j];
//         mp[arr[j]]++;
//         while(sum>K && i<=j){
//             sum -= arr[i];
//             mp[arr[i]]--;
//             if(mp[arr[i]]==0){
//                 mp.erase(arr[i]);
//             }
//             i++;
//         }
//         if(sum == K){
//             maxLen = max(maxLen, j-i+1);
//         }
//         j++;
//     }
//     return maxLen;
// }
int longestSubarraySumK(vector<int>& arr, int K){
    int n = arr.size();
    int prefixSum =0, maxLen =0;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        prefixSum += arr[i];
        if(prefixSum == K){
            maxLen = i+1;
        }
        if(mp.find(prefixSum-K)!=mp.end()){
            maxLen = max(maxLen, i-mp[prefixSum-K]);
        }
        if(mp.find(prefixSum) == mp.end()){
            mp[prefixSum] = i;
        }
    }
    return maxLen;
}
int main(){
    int N, K;
    cin>> N >> K;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int ans = longestSubarraySumK(arr,K);
    cout << ans << endl;;
    return 0;
}
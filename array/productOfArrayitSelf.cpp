#include<bits/stdc++.h>
using namespace std;
// Product of Array Except Self 
vector<int> findProduct(vector<int>&arr){ // Time complexity O(n) and space complexity O(n)
    int n = arr.size();
    int prefix = 1;
    vector<int> res(n,1);
    for(int i=0; i<n; i++){
        res[i] = prefix; // store the prefix product
        prefix *= arr[i]; // update the prefix product
    }
    int suffix = 1;
    for(int i= n-1; i>=0; i--){
        res[i] *= suffix; // multiply the suffix product with the prefix product
        suffix *= arr[i]; // update the suffix product
    }
    return res;
}
int main(){
    vector<int> arr = {1,2,3,4};
    vector<int> ans = findProduct(arr);
    for(int i: ans){
        cout << i << " ";
    } 
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr, int n){
    vector<int> left(n,1);
    vector<int> right(n, 1);
    vector<int> result(n,1);
    for(int i=1; i<n; i++){
        left[i] = left[i-1]*arr[i-1];
    }
    for(int i=n-2; i>=0; i--){
        right[i]  = right[i+1]*arr[i+1];
    }
    for(int i=0; i<n; i++){
        result[i]  = left[i]*right[i];
    }
    return result;
}
int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    int n = arr.size();
    vector<int> result = solve(arr, n);
    for(int i=0; i<n; i++){
        cout << result[i] << " ";
    }
    return 0;
}
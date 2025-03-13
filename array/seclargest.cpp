#include<bits/stdc++.h>
using namespace std;
int secLar(vector<int>&arr){
    int n = arr.size();
    if(n<2) return -1;
    int largest = INT_MIN;
    int secLargest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]> largest){
            secLargest = largest;
            largest  = arr[i];
        }else if(arr[i] > secLargest && arr[i] != largest){
            secLargest = arr[i];
        }
    }
    return (secLargest == INT_MIN)?-1:secLargest;
}
int main(){
    int N;
    cin>> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int ans = secLar(arr);
    cout << ans<< endl;
    return 0;
}
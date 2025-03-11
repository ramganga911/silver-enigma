#include<bits/stdc++.h>
using namespace std;
// int solve(vector<int>&arr, int n){ // time complexity O(n^2)
//     long long maxProd = arr[0];
//     for(int i=0; i<n; i++){
//         long long  mul =1;
//         for(int j=i; j<n; j++){
//             mul = mul*arr[j];
//             maxProd = max(maxProd, mul);
//         }
//     }
//     return maxProd;
// }
long long solve(vector<int>&arr, int n){ // Time Complexity O(n)
    long long maxProd = arr[0];
    long long leftProd = 1;
    long long rightProd =1;
    for(int i=0; i<n; i++){
        leftProd = (leftProd==0)?1:leftProd;
        rightProd = (rightProd==0)?1:rightProd;
        leftProd = leftProd*arr[i];
        rightProd = rightProd*arr[n-i-1];
        maxProd = max(maxProd, max(leftProd,rightProd));
    }
    return maxProd;
}
int main(){
    vector<int> arr ={2,3,-2,4};
    int n = arr.size();
    int maxProd = solve(arr, n);
    cout << "Maximum product subarray: " << maxProd;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// int sumFun(int n){
//     if(n<=0){
//         return 0;
//     }else{
//         return n+sumFun(n-1);
//     }
// }
int sumFun(vector<int>&arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }else{
        return arr.back()+sumFun(arr);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum = sumFun(arr);
    cout << sum;
    return 0;
}
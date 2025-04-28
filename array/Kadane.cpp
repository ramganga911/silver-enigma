#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int>&arr){
    int maxSum = INT_MIN;
    int curr_sum =0;
    int start=0,end=0, tempStart=0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(curr_sum+arr[i]<arr[i]){
            curr_sum = arr[i];
            tempStart=i;
        }else{
            curr_sum+=arr[i];
        }
        if(curr_sum> maxSum){
            maxSum = curr_sum;
            start = tempStart;
            end = i;
        }
    }
    for(int i=start; i<=end; i++){
        cout << arr[i]<<" ";
    }
    return maxSum;
}
int main(){
    vector<int>arr = {2, 3, -8, 7, -1, 2, 3};
    int maxSum = maxSubarraySum(arr);
    cout << "maxSum :"<< maxSum;
    return 0;
}
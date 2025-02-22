#include<bits/stdc++.h>
using namespace std;
// maximum product of subarray
// int maximumProduct(vector<int>&nums){ // Time complexity O(n^2) and space complexity O(1)
//     int n = nums.size();
//     int res = nums[0];
//     for(int i=1; i<n; i++){
//         int mul = 1;
//         for(int j=i; j<n; j++){
//             mul*= nums[j];
//             res = max(res, mul);
//         }

//     }
//     return res;
// }
int maximumProduct(vector<int>&nums){ // Time complexity O(n) and space complexity O(1)
    int n = nums.size();
    int maxProd = INT_MIN;
    int leftToright = 1; // product from left to right
    int rightToleft = 1; // product from right to left
    for(int i=0; i<n; i++){
        if(leftToright ==0){
            leftToright =1;
        }
        if(rightToleft ==0){
            rightToleft =1;
        }
        leftToright *= nums[i];
        int j= n-i-1;
        rightToleft *= nums[j];
        maxProd = max(maxProd, max(leftToright, rightToleft));
    }
    return maxProd;
}
int main(){
    vector<int> nums = {2,3,-2,4};
    int ans = maximumProduct(nums);
    cout << "Maximum product of subarray is: " << ans;
    return 0;
}
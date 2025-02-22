#include<bits/stdc++.h>
using namespace std;
// Pair in Sorted Rotated Array
bool pairInSortedRotatedArr(vector<int>&arr, int target){ // Time complexity O(n) and space complexity O(1)
    int i;
    int n = arr.size();
    for(i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            break;
        }
    }
    int l = (i+1)%n;
    int r = i;
    while(l!=r){
        if(arr[l]+arr[r] == target){
            return true;
        }else if(arr[l]+arr[r]<target){
            l = (l+1)%n;
        }else{
            r = (r+n-1)%n;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {11, 15, 6, 8, 9, 10};
    int target = 16;
    cout << pairInSortedRotatedArr(arr, target);
    return 0;
}
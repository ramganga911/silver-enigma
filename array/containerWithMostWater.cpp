#include<bits/stdc++.h>
using namespace std;
int containerWithMostWater(vector<int>&arr){
    int n = arr.size();
    int left = 0, right = n-1;
    int area =0;
    int maxArea = INT_MIN;
    while(left < right){
        int width = right - left;
        int height = 0;
        if(arr[left]<arr[right]){
            height = arr[left];
            left++;
        }else{
            height = arr[right];
            right--;
        }
        area = width*height;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}
int main(){
    int T;
    cin>> T;
    while(T--){
        int N;
        cin>>N;
        vector<int>arr(N);
        for(int i=0; i<N; i++){
            cin>> arr[i];
        }
        int ans = containerWithMostWater(arr);
        cout << ans;
    }
    return 0;
}
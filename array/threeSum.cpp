#include<bits/stdc++.h>
using namespace std;
// 3 Sum
void threeSum(vector<int>&arr){ // Time complexity O(N^2)
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-2; i++){
        if(arr[i]==arr[i-1]){
            continue;
        }
        int left = i+1;
        int right = n-1;
        while(left < right){
            int sum = arr[i]+arr[left]+arr[right];
            if(sum == 0){
                ans.push_back({arr[i], arr[left], arr[right]});
                while(left <right && arr[left]==arr[left+1]){
                    left++;
                }
                while(left<right && arr[right]==arr[right+1]){
                    right--;
                }
                left++;
                right--;
            }else if(sum<0){
                left++;
            }else{
                right--;
            }
        }

    }
    for(auto num: ans){
        for(int x: num){
            cout << x<< " ";
        }
        cout << endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int>arr(N);
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        threeSum(arr);
    }
    return 0;
}
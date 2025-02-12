#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 3, 5, 5}; // time complexity O(n) and space complexity O(1)
    int n = arr.size();
    int ans = 0, freq =0;
    for(int i=0; i<n; i++){
        if(freq ==0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }else{
            freq--;
        }
    }
    cout << "Majority Element n/2 times is: "<<ans;
    return 0;
}
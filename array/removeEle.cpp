#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,2,2,3};
    int val = 3;
    int n = arr.size();
    int i=0, j=0;
    while(j<n){
        if(arr[j]!=val){
            arr[i] = arr[j];
            i++;
        }
        j++;
    }
    cout<<i;
    return 0;
}
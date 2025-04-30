#include<bits/stdc++.h>
using namespace std;
void sortAlmosrtSortedArray(vector<int>&arr, int k){
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int n = arr.size();
    for(int i=0; i<=k && i<n; i++){
        minHeap.push(arr[i]);
    }
    int idx=0;
    for(int i=k+1; i<n; i++){
        arr[idx++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]); 
    }
    while(!minHeap.empty()){
        arr[idx++] = minHeap.top();
        minHeap.pop();
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>> n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sortAlmosrtSortedArray(arr,k);
        for(int i=0; i<n; i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Rotate Array by d places
// void rotateArrBydPlace(vector<int>&arr, int d, int n){ // Time complexity O(n*d) and space complexity O(1)
//     for(int i=0; i<d; i++){
//         int first = arr[0];
//         for(int i=0; i<n-1; i++){
//             arr[i] = arr[i+1];
//         }
//         arr[n-1] = first;
//     }
// }
void reverse(vector<int>&arr, int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
// Rotate Array by d places
void rotateArrBydPlace(vector<int>&arr, int d, int n){ // Time complexity O(n) and space complexity O(1)
    reverse(arr.begin(), arr.begin()+d); // reverse first d elements
    reverse(arr.begin()+d, arr.end()); // reverse remaining elements
    reverse(arr.begin(), arr.end()); // reverse the whole array
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
    int d = 2;
    int n = arr.size();
    rotateArrBydPlace(arr, d, n);
    for(auto x: arr){
        cout << x << " ";
    }
    return 0;
}
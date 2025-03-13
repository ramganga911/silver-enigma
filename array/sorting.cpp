#include<bits/stdc++.h>
using namespace std;
// void sortArray(vector<int>&arr){
//     // Bubble sort 
//     int n = arr.size();
//     bool swapped;
//     for(int i=0; i<n-1; i++){
//         swapped  = false;
//         for(int j=0; j<n-i-1; j++){
//             if(arr[j]> arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//                 swapped = true;
//             }
//         }
//         if(!swapped) break;
//     }
// }
// void sortArray(vector<int>&arr){
//     // Selection Sort
//     int n = arr.size();
//     for(int i=0; i<n-1; i++){
//         int minIdx = i;
//         for(int j =i+1; j<n; j++){
//             if(arr[j]<arr[minIdx]){
//                 minIdx = j;
//             }
//         }
//         swap(arr[i], arr[minIdx]);
//     }

// }
// int partition(vector<int>&arr, int low, int high){
//     int n = arr.size();
//     int i = low-1; // idx of smallest ele
//     int pivot = arr[high];
//     for(int j=low; j<high; j++){
//         if(arr[j] < pivot){ // if ele is smaller the pivot
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i+1], arr[high]);
//     return i+1;

// }
// void quickSort(vector<int>&arr, int start, int end){
//     if(start< end){
//         int pi = partition(arr,start,end);
//         quickSort(arr,start, pi-1);
//         quickSort(arr,pi+1,end);
//     }
// }
void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void sortArray(vector<int>&arr){
    int n = arr.size();
    insertionSort(arr);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        sortArray(arr);
        for(int num: arr){
            cout << num <<" ";
        }
        cout << endl;
    }
    return 0;
}
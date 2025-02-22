#include<bits/stdc++.h>
using namespace std;
// Quick sort
// QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
// There are many different versions of quickSort that pick pivot in different ways.
// Always pick first element as pivot.
int partition(vector<int>&nums, int low, int high){ // Time complexity: O(nlogn) and Space complexity: O(1)
    int pivot = nums[high];
    int i = low -1;
    for(int j=low; j<= high-1; j++){
        if(nums[j] <pivot){
            i++;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[i+1], nums[high]);
    return i+1;
    
}
void quickSort(vector<int>&nums, int start, int end){
    if(start < end){
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot-1);
        quickSort(nums, pivot+1, end);
    }
}
int main(){
    vector<int> nums={0,2,4,5,1,3,6};
    int n = nums.size();
    quickSort(nums,0,n-1);
    cout << "Sorted Array: ";
    for(int it: nums){
        cout << it << " ";
    }
    return 0;
}
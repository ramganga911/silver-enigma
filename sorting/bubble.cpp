#include<bits/stdc++.h>
using namespace std;
// Bubble sort
// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
void bubbleSort(vector<int>&nums, int n){ // Time complexity: O(n^2) and Space complexity: O(1)
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}
int main(){
    vector<int> nums = {2, 1, 5, 3, 1, 0, 4};
    int n = nums.size();
    bubbleSort(nums,n);
    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Insertion sort
// Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
// The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
void insertionSort(vector<int>&nums, int n){ // Time complexity: O(n^2) and Space complexity: O(1)
    for(int i=1; i<n; i++){
        int key = nums[i]; // key is the element to be compared with the elements before it
        int j = i-1;
        // Move elements of nums[0..i-1], that are greater than key, to one position ahead of their current position
        while(j>=0 && nums[j]> key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}
int main(){
    vector<int> nums = {2, 1, 5, 3, 1, 0, 4};
    int n = nums.size();
    insertionSort(nums,n);
    for(int it : nums){
        cout << it << " ";
    }
    return 0;
}
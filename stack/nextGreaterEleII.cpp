#include<bits/stdc++.h>
using namespace std;
// Next Greater Element II
vector<int> nextGreaterElements(vector<int>& nums) { // Time complexity O(n) and space complexity O(n)
    int n = nums.size();
    vector<int> result(n,-1);
    stack<int> s;
    for(int i=2*n-1; i>=0; i--){ // 2*n-1 because we need to traverse the array twice
        while(s.size()>0 && nums[s.top()]<= nums[i%n]){ // if the current element is greater than the top element of the stack then pop the element
            s.pop();
        }
        result[i%n] = s.empty()?-1:nums[s.top()];
        s.push(i%n);
    }
    return result;
}
int main(){
    vector<int> nums = {1,2,3,4,3};
    vector<int> result = nextGreaterElements(nums);
    for(int i: result){
        cout << i<< " ";
    }
    return 0;
}
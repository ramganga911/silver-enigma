#include<bits/stdc++.h>
using namespace std;
// find longest consecutive sequence
int longestConsecutiveSequence(vector<int>& nums){ // Time complexity O(nlogn) and space complexity O(1)
    sort(nums.begin(),nums.end());
    int n = nums.size();
    if(n==0) return 0;
    int curr=1, ans =1;
    int prev = nums[0];
    for(int i=1; i<n; i++){
        if(nums[i]==prev+1){
            curr++;
        }else if(nums[i]!=prev){
            curr = 1;
        }
        ans = max(ans,curr);

        prev= nums[i];
    }
    return ans;
}
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = longestConsecutiveSequence(nums);
    cout << "Longest Consecutive Sequence: " << ans;
    return 0;
}
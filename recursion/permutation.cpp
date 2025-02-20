#include<bits/stdc++.h>
using namespace std;
void getPerMutation(vector<int>&nums, int idx, vector<vector<int>>&result){
    if(idx>=nums.size()){
        result.push_back({nums});
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        swap(nums[i], nums[idx]);
        getPerMutation(nums,idx+1, result);
        swap(nums[i], nums[idx]);
    }
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result;
    vector<int> ans;
    getPerMutation(nums,0, result);
    cout << "Permutations are: " << endl;
    for(auto x : result){
        for(auto y: x){
            cout << y << " ";
        }cout << endl;
    }
    return 0;
}
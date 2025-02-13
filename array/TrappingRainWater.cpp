#include<bits/stdc++.h>
using namespace std;
// Trapping Rain Water
int TrappingRainWater(vector<int>& height){ // Time complexity O(n) and space complexity O(n)
    int n = height.size();
    if(n==0) return 0;
    int left[n],right[n];
    left[0] = height[0];
    right[n-1] = height[n-1];
    for(int i=1; i<n; i++){ // left array stores the maximum height of the left side of the current element
        left[i] = max(left[i-1], height[i]);
    }
    for(int i=n-2; i>=0; i--){ // right array stores the maximum height of the right side of the current element
        right[i] = max(right[i+1], height[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){ // ans stores the trapped rain water
        ans+=(min(left[i],right[i])-height[i]); // trapped rain water = min(left[i],right[i])-height[i] Ex: trapped rain water = min(2,2)-1 = 1
    }
    return ans;
}
int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = TrappingRainWater(height);
    cout << "Trapped Rain Water: " << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Container With Most Water
int findmaxWater(vector<int>& arr){ //Time complexity O(n) and space complexity O(1)
    int n = arr.size();
    int i=0, j=n-1;
    int maxWater = INT_MIN;
    int area = 0;
    
    while(i<j){
        int width = j-i;
        int height = 0;
        if(arr[i]< arr[j]){
            height = arr[i];
            i++;
        }else{
            height = arr[j];
            j--;
        }
        area = width*height;
        maxWater = max(maxWater,area);
    }
    return maxWater;

}
int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = findmaxWater(height);
    cout << "Container with most water: " << ans;
    return 0;
}
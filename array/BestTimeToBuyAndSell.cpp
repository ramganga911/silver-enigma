#include<bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock
int maxProfit(vector<int> &arr) // Time complexity O(n) and space complexity O(1)
{ 
    int minBuy = arr[0];
    int maxProfit = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        minBuy = min(minBuy, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minBuy);
    }
    return maxProfit;
}
int main(){
    vector<int> arr= {7,1,5,3,6,4};
    int ans = maxProfit(arr);
    cout<< "Maximum Profit: "<<ans;
    return 0;
}
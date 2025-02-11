#include<bits/stdc++.h>
using namespace std;
//find the stock span of the stock prices
//span = maximum consecutive days the stock price was less than or equal to the current day
vector<int> findStockSpan(vector<int>&prices){ // time complexity O(n) and space complexity O(n)
    vector<int> ans;
    stack<int> st;
    int n = prices.size();
    for(int i=0; i<n; i++){
        while(!st.empty() && prices[st.top()]<= prices[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(i+1);
        }else{
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    return ans;

}
int main(){
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = findStockSpan(prices);
    for(int i: ans){
        cout << i <<" ";
    }
    return 0;
}
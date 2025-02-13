#include<bits/stdc++.h>
using namespace std;
// Largest Area in Histogram
int largestAreaInHistogram(vector<int>&height){ // Time complexity O(n) and space complexity O(n)
    int n = height.size();
    vector<int> right(n,0);
    vector<int> left(n,0);
    stack<int> st;
    // right smaller element
    for(int i=n-1; i>=0; i--){
        while(st.size()>0 && height[st.top()]>= height[i]){ // if the current element is greater than the top element of the stack then pop the element
            st.pop();
        }
        right[i] = st.empty()?n:st.top();
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    // left smaller element
    for(int i=0; i<n; i++){
        while(st.size()>0 && height[st.top()]>= height[i]){ // if the current element is greater than the top element of the stack then pop the element
            st.pop();
        }
        left[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    int maxArea =0;
    for(int i=0; i<n; i++){
        int width = (right[i]-left[i]-1); // width = right smaller element - left smaller element - 1
        int currArea = height[i]* width; // current area = height[i]*width
        maxArea = max(maxArea, currArea);
    }
    return maxArea;

}
int main(){
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int ans = largestAreaInHistogram(height);
    cout << "Largest Area in Histogram: " << ans;
    return 0;
}
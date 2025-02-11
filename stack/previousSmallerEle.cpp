#include<bits/stdc++.h>
using namespace std;
//find the previous smaller element in the array
vector<int> findPreviousSmaller(vector<int>&arr){ //Time complexity O(n) and space complexity O(n)
    int n  = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(st.size()>0 && st.top()>= arr[i]){
            st.pop();
        }
        if(st.size()==0){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 5, 0, 3, 4, 5}; //output should be -1 1 -1 0 3 4
    vector<int> ans = findPreviousSmaller(arr);
    for(int i: ans){
        cout << i <<" ";
    }
    return 0;
}
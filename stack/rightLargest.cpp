#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), res(n,-1);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    stack<int>st;
    for(int i=n-1; i>=0; --i){
        while(!st.empty()&& st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(int x:res){
        cout << x<<" ";
    }
    return 0;
}
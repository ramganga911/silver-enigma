#include<bits/stdc++.h>
using namespace std;
int getCelebrity(vector<vector<int>>arr){
    stack<int> st;
    int n = arr.size();
    for(int i =0; i<n; i++){
        st.push(i);
        
    }
    while(st.size()>1){
        int i = st.top();
        st.pop();
        int j= st.top();
        st.pop();
        if(arr[i][j]==0){
            st.push(i);
        }else{
            st.push(j);
        }
    }
    int celeb = st.top();
    for(int i=0; i<n; i++){
        if((i!=celeb) &&(arr[i][celeb] == 0 || arr[celeb][i]==1)){
            return -1;
        }
    }
    return celeb;

}
int main(){
    vector<vector<int>> arr ={
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int ans  = getCelebrity(arr);
    cout<< "celebrity is : " << ans<< endl;
    return 0;
}
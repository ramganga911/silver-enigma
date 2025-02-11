#include<bits/stdc++.h>
using namespace std;
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
bool findValidParenthesis(string s){ //O(n) time complexity and O(n) space complexity
    stack<char> st;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }else{
            if(st.size()==0){
                return false;
            } else if((s[i]==')'&&st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.size()==0;
}
int main(){
    string s = "({{}]})";
    bool ans = findValidParenthesis(s);
    if(ans){
        cout << "Valid Parenthesis";
    }else{
        cout << "Invalid Parenthesis";
    }
    return 0;
}
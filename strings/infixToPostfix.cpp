#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string exp){
    stack<char> st;
    string result="";
    int n = exp.size();
    for(int i=0; i<n; i++){
        char ch = exp[i];
        if((ch>='a' && ch<='z')|| (ch >='A' && ch<='Z') ||(ch>='0' && ch<='9')){
            result+=ch;
        }else if(ch=='('){
            st.push(ch);
        }else if(ch==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty()&& prec(ch)<= prec(st.top())){
                result+= st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string ans= infixToPostfix(exp);
    cout << ans;
    return 0;
}
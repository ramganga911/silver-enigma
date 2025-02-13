#include<bits/stdc++.h>
using namespace std;
// Valid Palindrome 
bool check(string s){ // Time complexity O(n) and space complexity O(1)
    string str = "";
    for(char ch : s){
        if(isalnum(ch)){
            str+=tolower(ch);
        }
    }
    int n = str.size();
    int i=0, j=n-1;
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    bool isPalin = check(s);
    if(isPalin){
        cout <<"Valid Palindrome";
    }else{
        cout << "Invalid Palindrome";
    }
    return 0;
}
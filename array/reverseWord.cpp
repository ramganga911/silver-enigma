#include<bits/stdc++.h>
using namespace std;
// Reverse the words in a string 
string reverseWord(string s){ // Time complexity O(n) and space complexity O(1)
    int n = s.size();
    string word = "";
    string result = "";
    for(int i=0; i<n; i++){ 
        if(s[i]==' '){
            if(word.size()>0){ // for the first word
                if(result.size()>0) result = " "+result; // for the rest of the words
                result = word + result; // for the rest of the words
                word = "";  // for the rest of the words
            }
        }else{
            word += s[i]; 
        }
    }
    if(word.size()>0){ // for the last word
        if(result.size()>0) result = " "+result;
        result = word + result;
    }
    return result;
}
int main(){
    string s = "hello my name is Ramganga Kumar";
    string result = reverseWord(s);
    cout<<result;
    return 0;
}
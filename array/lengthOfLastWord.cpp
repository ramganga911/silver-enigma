#include<bits/stdc++.h>
using namespace std;
// Length of last Word in a string
int findLastWordLength(string s){ // Time complexity O(n) and space complexity O(1)
    int n= s.size()-1;
    int i = n;
    int length =0;
    while(i>= 0 && s[i]==' '){
        i--;
    }
    while(i>=0 && s[i]!= ' '){
        length++;
        i--;
    }
    return length;
}
int main(){
    string s = "   fly me   to   the moon  ";
    int ans = findLastWordLength(s);
    cout <<"Length of the last word is: " << ans;   
    return 0;
}
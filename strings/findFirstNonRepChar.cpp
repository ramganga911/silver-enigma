#include<bits/stdc++.h>
using namespace std;
char firstRepChar(string S){
    unordered_map<char,int> mp;
    for(char ch: S){
        mp[ch]++;
    }
    for(char ch:S){
        if(mp[ch]==1){
            return ch;
        }
    }
    return '-1';
}
int main(){
    string S;
    cin >> S;
    cout << firstRepChar(S) << endl;

    return 0;
}
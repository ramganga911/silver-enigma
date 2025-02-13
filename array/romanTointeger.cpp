#include<bits/stdc++.h>
using namespace std;
// Roman to Integer
int romanToInt(string s){ // Time complexity O(n) and space complexity O(1)
    unordered_map<char,int> roman = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int n = s.size();
    int result =0; 
    for(int i=0; i<n; i++){
        int value = roman[s[i]];
        if(i+1<n && value < roman[s[i+1]]){ // if the current value is less than the next value then subtract the current value from the result
            result -= value;
        }else{
            result += value;
        }
    }
    return result;
}
int main(){
    string s = "MCMXCIV"; // 1994
    int ans = romanToInt(s);
    cout << "Roman to Integer: " << ans;
    return 0;
}
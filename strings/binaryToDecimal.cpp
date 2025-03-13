#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string s){
    int decimal =0;
    int power = 1;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='1'){
            decimal+=power;
        }
        power*=2; // move to the next power of 2
    }
    return decimal;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>> s;
        cout << binaryToDecimal(s) << endl;
    }
    return 0;
}
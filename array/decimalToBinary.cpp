#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int N){
    string binary ="";
    if(N==0) return "0";
    while(N>0){
        binary += (N%2) + '0';
        N/=2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
int main(){
    int n;
    cin>>n;
    cout << decimalToBinary(n)<< endl;
    return 0;
}
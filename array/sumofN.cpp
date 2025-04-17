#include<bits/stdc++.h>
using namespace std;
int sumFun(int n){
    if(n<=0){
        return 0;
    }else{
        return n+sumFun(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    int sum = sumFun(n);
    cout << sum;
    return 0;
}
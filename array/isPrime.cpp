#include<bits/stdc++.h>
using namespace std;
// bool isPrime(int n){
//     if(n<=1) return false;
//     for(int i=2; i*i<=n; i++){
//         if(n%i==0) return false;
//     }
//     return true;
// }
// int countDivisors(int N){
//     int count =0;
//     for(int i=1; i*i<= N; i++){
//         if(N%i==0){
//             count++;
//             if(i!=N/i) count++;
//         }
//     }
//     return count;
// }
// int countSetBits(int N){
//     int count =0;
//     while(N>0){
//         count+= (N&1); // check last bit(ON or OFF)
//         N>>=1; // Shift right to check the next bits
//     }
//     return count;
// }
bool isPowerofTwo(int N){
    return (N>0 && (N&(N-1))==0);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        // if(isPrime(N)){
        //     cout << "Yes"<<endl;
        // }else{
        //     cout << "No"<< endl;
        // }
        // cout << countDivisors(N) << endl;
        // cout << countSetBits(N) << endl;
        if(isPowerofTwo(N)){
            cout <<"Yes" << endl;
        }else{
            cout <<"No" << endl;
        }
    }
    return 0;
}
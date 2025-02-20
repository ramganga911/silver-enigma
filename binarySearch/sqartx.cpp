#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
    if(n == 0 || n == 1) return n;
    int left =1, right =n;
    int result =0;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(mid <= n/mid){
            result = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return result;
}
int main(){
    int n = 4;
    int ans = sqrt(n);
    cout << "Square root of " << n << " is: " << ans;

    return 0;
}
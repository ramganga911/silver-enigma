#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char ch : s){
            if(isalnum(ch)){  
                str += tolower(ch);  
            }
        }
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]){  
                return false;
            }
            i++;
            j--;
        }
        
        return true; 
    }
};
int main(){
    Solution obj;
    string s = "A man, a plan, a canal: Panama";
    cout<<obj.isPalindrome(s) << endl;
    return 0;
}
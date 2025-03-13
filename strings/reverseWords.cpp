#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    stringstream ss(s);
    vector<string> words;
    string word;
    // split words and store in vector
    while(ss>>word){
        words.push_back(word);
    }
    // reverse the order of words
    reverse(words.begin(), words.end());
    //print the reversed words
    string result ="";
    for(int i=0; i<words.size(); i++){
        if(i>0) result += " "; // add space btw words
        result+= words[i];
    }
    return result;
}
int main(){
    string S;
    getline(cin, S);
    cout << reverseWords(S) << endl;
    return 0;
}
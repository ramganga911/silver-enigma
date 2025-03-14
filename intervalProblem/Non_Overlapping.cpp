#include<bits/stdc++.h>
using namespace std;
// int removeOverlapping(vector<vector<int>>&intervals){
//     int n = intervals.size();
//     if(n==0) return 0;
//     sort(intervals.begin(), intervals.end(),[](vector<int>&a, vector<int>&b){
//         return a[1]<b[1];
//     });
//     int count =0;
//     int lastEnd = intervals[0][1];
//     for(int i=1; i<n; i++){
//         if(intervals[i][0] < lastEnd){
//             count++;
//         }else{
//             lastEnd = intervals[i][1];
//         }
//     }
//     return count;
// }
void findNonOverlappingIntervals(vector<vector<int>>&intervals)
{ // Overall Complexity: O(N log N)
    int n = intervals.size();
    if(n==0) return;
    //sort
    sort(intervals.begin(), intervals.end()); // Sorting: O(N log N)
    vector<vector<int>>result;
    //find gap b/w consecutive intervals
    for(int i=1; i<n; i++)
    { // Finding gaps: O(N)
        if(intervals[i][0]> intervals[i-1][1]){
            result.push_back({intervals[i-1][1], intervals[i][0]});
        }
    }
    // print the non-overlapping gaps
    for(auto& interval: result){
        cout << "[" << interval[0] <<"," << interval[1]<<"]\n";
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<vector<int>> intervals(N, vector<int>(2));
        //input
        for(int i=0; i<N; i++){
            cin>> intervals[i][0]>>intervals[i][1];
        }
        // cout << removeOverlapping(intervals)<<endl;
        findNonOverlappingIntervals(intervals);
    }
    
    return 0;
}
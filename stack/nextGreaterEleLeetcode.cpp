#include<bits/stdc++.h>
using namespace std;
// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) //time complexity O(n) and space complexity O(n)
{
    unordered_map<int, int> mp;
    stack<int> st;
    int n = nums2.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= nums2[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            mp[nums2[i]] = -1;
        }
        else
        {
            mp[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}
int main(){
    vector<int> nums1= {4,1,2};
    vector<int> nums2={1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}
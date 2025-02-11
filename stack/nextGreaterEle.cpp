#include <bits/stdc++.h>
using namespace std;
//find next greater element in the array
vector<int> findNextGreater(vector<int> &arr) // O(n) time complexity and O(n) space complexity
{
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = findNextGreater(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
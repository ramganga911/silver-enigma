#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), res(n, -1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= A[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(A[i]);
    }
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
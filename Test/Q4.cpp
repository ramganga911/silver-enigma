#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortAlmostSortedArray(vector<int> &A, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i <= k && i < A.size(); ++i)
    {
        minHeap.push(A[i]);
    }

    int index = 0;
    for (int i = k + 1; i < A.size(); ++i)
    {
        A[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(A[i]);
    }

    while (!minHeap.empty())
    {
        A[index++] = minHeap.top();
        minHeap.pop();
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }

        sortAlmostSortedArray(A, k);

        for (int i = 0; i < n; ++i)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
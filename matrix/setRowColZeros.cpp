#include <bits/stdc++.h>
using namespace std;
// Set Matrix Zeroes
void setMatZeros(vector<vector<int>> &mat) // Time complexity O(n*m) and space complexity O(n+m)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> rows(n, false), cols(m, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows[i] || cols[j])
            {
                mat[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    int n = mat.size();
    int m = mat[0].size();
    setMatZeros(mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
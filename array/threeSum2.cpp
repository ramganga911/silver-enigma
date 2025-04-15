#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0)
            {
                ans.push_back({arr[i], arr[left], arr[right]});

                while (left < right && arr[left] == arr[left + 1])
                    left++;
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<vector<int>> ans = findTriplets(arr, n);
        int num = ans.size();
        cout << num << endl;

        for (auto triplet : ans)
        {
            for (int x : triplet)
            {
                cout << x << " ";
            }
            cout << endl; 
        }
    }

    return 0;
}

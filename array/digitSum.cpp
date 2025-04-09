#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }
        cout << sum << endl;
    }

    return 0;
}
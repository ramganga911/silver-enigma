#include <bits/stdc++.h>
using namespace std;
// Integer to Roman 
string intToRoman(int num) // Time complexity O(1) and space complexity O(1)
{
    static vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};                      // 13
    static vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; // 13
    string result = "";
    for (int i = 0; i < 13; i++)
    {
        if (num == 0)
        {
            break;
        }
        int times = num / value[i];
        while (times--)
        {
            result += symbol[i];
        }
        num = num % value[i];
    }
    return result;
}
int main()
{
    int num = 58;
    string result = intToRoman(num);
    cout << "Integer to roman: " << result;
    return 0;
}
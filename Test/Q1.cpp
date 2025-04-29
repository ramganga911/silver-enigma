#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

class MedianCalculator
{
private:
    priority_queue<int> maxHeap;                            
    priority_queue<int, vector<int>, greater<int>> minHeap; 

public:
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    float getMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};

int main()
{
    int n;
    cin >> n;
    MedianCalculator mc;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        if (val == -999999)
        {
            cout << setprecision(1) << mc.getMedian() << " ";
        }
        else
        {
            mc.addNum(val);
        }
    }

    return 0;
}
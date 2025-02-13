#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
    priority_queue<long long,vector<long long>,greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;
        while (!minHeap.empty() && minHeap.top() < k) {
            if (minHeap.size() < 2) {
                return -1;
            }
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            long long newElement =min(x, y) * 2 + max(x, y);
            minHeap.push(newElement);
            operations++;
        }
        return operations;
    }
};

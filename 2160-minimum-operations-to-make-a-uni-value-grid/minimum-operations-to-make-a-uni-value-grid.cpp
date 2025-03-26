class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flattened; 
        for (const auto& row : grid) {
            for (const auto& num : row) {
                flattened.push_back(num);
            }
        }
        sort(flattened.begin(), flattened.end());
        int n = flattened.size();
        int median = flattened[n / 2]; 
        int count = 0;
        for (const auto& num : flattened) {
            if (abs(num - median) % x != 0) {
                return -1; 
            }
            count += abs(num - median) / x;
        }
        
        return count;
    }
};
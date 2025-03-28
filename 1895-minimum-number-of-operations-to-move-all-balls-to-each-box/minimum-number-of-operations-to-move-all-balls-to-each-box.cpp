class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        // Left pass
        int cumval = 0, sumval = 0;
        for(int i = 0; i < n; i++) {
            answer[i] += sumval;
            cumval += boxes[i] - '0';
            sumval += cumval;
        }
        
        // Right pass
        cumval = 0, sumval = 0;
        for(int i = n - 1; i >= 0; i--) {
            answer[i] += sumval;
            cumval += boxes[i] - '0';
            sumval += cumval;
        }
        
        return answer;
    }
};

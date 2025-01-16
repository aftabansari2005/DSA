class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        int zeroes = 0;
        int maxScore = INT_MIN;
        for (char ch : s) {
            if (ch == '1') ones++;
        }
        int currentZeroes = 0, currentOnes = ones;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                currentZeroes++;
            } else {
                currentOnes--;
            }

            int score = currentZeroes + currentOnes;
             maxScore=max(maxScore,score);
        }

        return maxScore;
    }
};

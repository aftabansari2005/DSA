class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> cumsum(s.size() + 1, 0); 
        for (auto& ele : shifts) {
            int start = ele[0];
            int end = ele[1];
            int x = (ele[2] == 1) ? 1 : -1;
            cumsum[start] += x;
            if (end + 1 < s.size()) {
                cumsum[end + 1] -= x;
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            cumsum[i] += cumsum[i - 1];
        }
        for (int i = 0; i < s.size(); ++i) {
            int shift = (s[i] - 'a' + cumsum[i]) % 26;
            if (shift < 0) {
                shift += 26;
            }
            s[i] = 'a' + shift;
        }

        return s;
    }
};

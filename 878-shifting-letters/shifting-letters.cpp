class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> sht(shifts.size());
        sht[shifts.size()-1]=shifts[shifts.size()-1];
        for (int i = shifts.size() - 2; i >= 0; i--) {
            sht[i] += shifts[i]+ sht[i+1];
        }
        for (int i = 0; i < s.size(); i++) {
            int shift = ((s[i] - 'a') + sht[i]) % 26;
            s[i] = shift + 'a';
        }
        return s;
    }
};
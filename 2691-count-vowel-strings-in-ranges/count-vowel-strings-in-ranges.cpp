class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n + 1, 0); // Initialize with size + 1 for 1-based indexing
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            string str = words[i];
            if ((str.front() == 'a' || str.front() == 'e' || str.front() == 'i' || str.front() == 'o' || str.front() == 'u') &&
                (str.back() == 'a' || str.back() == 'e' || str.back() == 'i' || str.back() == 'o' || str.back() == 'u')) {
                pref[i + 1] = pref[i] + 1;
            } else {
                pref[i + 1] = pref[i];
            }
        }

        for (auto& query : queries) {
            int li = query[0], ri = query[1];
            int countOfVowelStrings = pref[ri + 1] - pref[li];
            ans.push_back(countOfVowelStrings);
        }

        return ans;
    }
};

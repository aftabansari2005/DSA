class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            if ((bitA | bitB) != bitC) {
                if (bitC == 0) {
                    ans += bitA + bitB;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};

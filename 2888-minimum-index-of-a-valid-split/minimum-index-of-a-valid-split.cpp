class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                dominant = num;
                count = 1;
            } else if (num == dominant) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (int num : nums) {
            if (num == dominant) count++;
        }
        if (count * 2 <= nums.size()) return -1;
        int leftCount = 0, rightCount = count;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dominant) {
                leftCount++;
                rightCount--;
            }
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (nums.size() - i - 1)) {
                return i;
            }
        }
        return -1;
    }
};
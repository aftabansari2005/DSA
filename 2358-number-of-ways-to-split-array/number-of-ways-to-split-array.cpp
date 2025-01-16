class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
         long long sum;
         int ans=0;
         for(auto val:nums)sum+=val;
         long long cursum=0;
         for(int i =0;i<nums.size()-1;i++){
            cursum+=nums[i];
            if(cursum>=(sum-cursum))ans++;
         }
         return ans;
    }
};
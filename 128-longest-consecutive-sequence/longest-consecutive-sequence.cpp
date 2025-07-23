class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int cnt=1;
        int maxi=0;
        int prev=INT_MIN;
        for(auto & it : s){
            if(prev+1==it){
                cnt++;
            }
            else{
                cnt=1;
            }
            prev=it;

        
            maxi=max(maxi,cnt);
           }
        
        return maxi;
    }
};
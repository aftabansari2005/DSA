class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans=0;
        for(int i =0;i<s.size();i++){
            auto c1=s[i]-'a';
            auto c2=t[i]-'a';
            long long cost1=0,cost2=0;
            while(c1!=c2){
                cost1+=nextCost[c1];
                c1=(c1+1)%26;
            }
            c1=s[i]-'a';
            while(c1!=c2){
                cost2+=previousCost[c1];
                c1=(c1-1+26)%26;
            }
            ans+=min(cost1,cost2);
        }
        return ans;
    }
};
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
         int ans=0;
          int odd=0,even=0;
        for(int i=0;i<position.size();i++){
           if(position[i]%2==1)odd++;
           else{
            even++;
           }
           ans=min(odd,even);
        }
        return ans;
    }

};
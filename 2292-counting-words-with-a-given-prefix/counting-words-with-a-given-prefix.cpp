class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n1=pref.size();
        int count =0;
        for(auto & ele : words){
            int n2=ele.size();
            if(n1>n2)continue;
            else{
                if(ele.substr(0,n1)==pref)count++;
            }
        }
        return count;
    }
};
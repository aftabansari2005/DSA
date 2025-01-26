class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
         int n1=s.size();
        int count =0;
        for(auto & ele : words){
            int n2=ele.size();
            if(n1<n2)continue;
            else{
                if(s.substr(0,n2)==ele)count++;
            }
        }
        return count;
    }
};
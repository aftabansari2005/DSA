class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(auto & ele : words){
            for(auto & word:words){
                if(ele!=word){
                    if(word.find(ele)!=string::npos){
                    ans.push_back(ele);
                    break;
                    }
                
            }

        }

    }
    return ans;

    }
};
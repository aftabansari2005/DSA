class Solution {
public:
    long long numOfSubsequences(string s) {
        int n= s.size();
        long long total=0;
         int  tcount =0;
        long long ctcount=0;
        vector<int> suffixTcount(s.size(),0);
        for(int i =n-1; i>=0;i--){
            if(s[i]=='T'){
                tcount++;
            }
            else if(s[i]=='C'){
                ctcount+=tcount;
            }
            else if(s[i]=='L'){
                total+=ctcount;
            }
            suffixTcount[i]=tcount;
        }
        long long afterL=ctcount;
        int lcount =0;
        long long  lccount=0;
        long long afterC=0;
        long long aftert=0;
        for(int i =0 ;i< n ;i++){
            if(s[i]=='L'){
                lcount++;
            }
            if(s[i]=='C'){
                lccount+=lcount;
            }
            afterC=max(afterC,1LL*lcount*suffixTcount[i]);
        }
        aftert=lccount;
        long long maxgain=max(afterC,max(aftert,afterL));
        return total + maxgain;

    }
};


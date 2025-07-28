class Solution {
public:
    int sqr(int num){
       if (num==1) return 1;
       int left =1 ; int  right = num/2;
       while(left <= right){
        int mid = left + (right - left)/2;
        long long sq = 1LL*mid*mid;
        if(sq == num)return mid;
        else if( sq<num){
            left = mid+1;
        }
        else right=mid-1;
       }
       return right;

    }
    bool isPerfectSquare(int num) {
        int ans =sqr(num);
        return (ans*1LL*ans == num);
    }
};
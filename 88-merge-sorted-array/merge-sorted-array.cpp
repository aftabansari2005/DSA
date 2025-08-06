class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

     int gap=(m+n+1)/2;
     int k=0;
     for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
     while(gap>0){
        int i =0 ;
        int j =i+gap;
        while(j<nums1.size()){
            if(nums1[i]>nums1[j])swap(nums1[i],nums1[j]);
            i++;
            j++;
        }
        if(gap==1)break;
        gap=(gap+1)/2;
     }

    }
};
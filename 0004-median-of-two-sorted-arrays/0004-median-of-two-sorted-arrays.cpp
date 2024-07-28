class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1); 
        int med = (n1 + n2 + 1)/2; //until which index the median can actually lie
        int n = n1 + n2; 
        int left = 0, right = n1; //perform binary search on the 1st array, rest values can be derived from the 1st array
         
        while(left <= right){
            int mid1 = (left + right)/2; 
            int mid2 = med - mid1; //mid2 is the index of 2nd array found from median index and the mid1 index
             
            int l1 = INT_MIN, l2 = INT_MIN; 
            int r1 = INT_MAX, r2 = INT_MAX; 

            if(mid1 < n1) r1 = nums1[mid1]; //just to ensure the mid index is in bound 
            if(mid2 < n2) r2 = nums2[mid2]; //just to ensure the mid index is in bound 

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1]; // top avoid accessing negative index
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1]; 
            
            //compare l1 l2 and r1 r2 

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1){
                    return max(l1,l2); 
                } else {
                    return ((double) (max(l1,l2) + min(r1,r2))) / 2.0; 
                }
            } else if(l1 > r2) {
                right = mid1 - 1; 
            } else left = mid1 + 1; 
        }
    return -1; 
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);  
        }

        int m = nums1.size(); 
        int n = nums2.size(); 

        int low = 0; 
        int high = m; 
        int totalLeft = (m + n + 1)/2; 
        while(low <= high){
            int cutA = low + (high - low) / 2; 
            int cutB = totalLeft - cutA; 

            int Aleft = (cutA == 0) ? INT_MIN : nums1[cutA  - 1]; 
            int Aright = (cutA == m) ? INT_MAX : nums1[cutA]; 
            int Bleft = (cutB == 0) ? INT_MIN : nums2[cutB - 1]; 
            int Bright = (cutB == n) ? INT_MAX : nums2[cutB]; 

            if(Aleft <= Bright && Bleft <= Aright){
                if((m+n) % 2 == 1){
                return max(Aleft, Bleft); 
                } else 
                    return ((max(Aleft, Bleft) + min(Aright, Bright)) / 2.0); 
            } else if(Aleft > Bright){
                high = cutA - 1;
            } else low = cutA + 1; 
        }
        return 0.0; 
    }
};
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1; 
        int left = 1;
        int right = *max_element(nums.begin(), nums.end()); 
        int ans = 0; 
        while(left<=right){
            int mid = left + (right - left)/2; 
            if(possible(nums, threshold, mid)){
                ans = mid; 
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans; 
    }

    bool possible(vector<int>& nums, int threshold, int mid){
        int divide = 1, sum=0; 
        for(int i=0; i<nums.size(); i++){
            divide = ceil(nums[i]/double (mid));
            sum += divide; 
        }
        return (sum <= threshold); 
    }
};
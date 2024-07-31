class Solution {
public:
    int findMin(vector<int>& nums) {
        //approach -> keep min from the sorted part and discard that part as we have already got the min from that, then keep eliminating the search space
        int left=0, right = nums.size() - 1; 
        int minElement = INT_MAX; //find min using min()
        while(left <= right){
            int mid = left + (right-left)/2; 



            //if the whole array is sorted, return the first element => nums[left]
            if(nums[left] <= nums[right]){
                minElement = min(minElement, nums[left]); 
                break; 
            }

            //if left part is sorted 
            if(nums[left] <= nums[mid]){
                //keep the minimum and discard this part of the array
                minElement = min(minElement, nums[left]); 
                left = mid + 1; 
            } else {
                //keep the minimum and discard this part
                minElement = min(minElement, nums[mid]); 
                right = mid - 1; 
            }
        }
        return minElement; 
    }
};
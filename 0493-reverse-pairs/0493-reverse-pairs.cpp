class Solution {
public:

    int merge(vector<int>& nums, int low, int mid,  int high){
        int count = 0; 
        vector<int> temp; 
        int left = low; 
        int right = mid + 1; 
        int j = mid + 1;
        for(int i=low; i<=mid; i++){
            while( j<=high && (long long) nums[i] > 2LL * nums[j]){
                j++; 
            }
            count += (j-(mid+1)); 
        }

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]); 
            } else {
                temp.push_back(nums[right++]); 
            }
        }
        while(left <= mid) temp.push_back(nums[left++]); 
        while(right <= high) temp.push_back(nums[right++]); 

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low]; 
        }
        return count; 
    }

    int countPairs(vector<int>& nums, int low, int high){
        int count = 0; 
        if(low < high){
            int mid = (low + high) / 2; 
            count += countPairs(nums, low, mid); 
            count += countPairs(nums, mid+ 1, high); 
            count += merge(nums, low, mid, high); 
        }
        return count; 
    }

    int reversePairs(vector<int>& nums) {
        return countPairs(nums, 0, nums.size() - 1); 
    }
};
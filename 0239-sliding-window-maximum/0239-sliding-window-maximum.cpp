class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; 
        int n = nums.size(); 
        deque<int> deq; 

        for(int i=0; i<n; i++){
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front(); 
            }

            while(!deq.empty() && nums[deq.back()] < nums[i]){
                deq.pop_back(); 
            }

            deq.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[deq.front()]); 
            }
        }
        return result; 
    }
};
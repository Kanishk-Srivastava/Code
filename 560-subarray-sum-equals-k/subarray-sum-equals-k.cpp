class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mpp; 
        int count=0; 
        int sum=0; 

        for(int i=0; i<nums.size(); i++){
            sum+= nums[i]; 

            if(sum == k){
                count++; 
            }
            int rem = sum - k; 
            if(mpp.find(rem) != mpp.end()){
                count+=mpp[rem].size(); 
            }
            mpp[sum].push_back(i); 
        }
        return count; 
    }
};
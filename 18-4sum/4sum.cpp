class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //1. take 4 pointers i,j,k,l i=0, j=i+1, k=j+1, l = n-1 and sort the given array
        //2. fix first two pointers and interate over each one by one
        //3. for every i and j check if they are not duplicates. if yes then just continue.
        //4. for each nums[i] + nums[j] + nums[k] + nums[l] check if == to target 
        //5. if sum>target then l-- 
        //6. if sum<target then k++
        //7. if == then push nums[i] nums[j] ..k and l to the temp array and then temp to ans array. 
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end()); 
        for(int i=0;i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue; 
            for(int j=i+1; j<nums.size(); j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue; 
                int k=j+1; 
                int l = nums.size() - 1; 
                while(k<l){
                    long long sum = nums[i]; 
                    sum+= nums[j]; 
                    sum+= nums[k]; 
                    sum+=nums[l];
                    if(sum == target){
                    vector<int> temp;
                        temp = {nums[i], nums[j], nums[k], nums[l]}; 
                        ans.push_back(temp); 
                        k++; l--; 
                        while(k<l && nums[k] == nums[k-1]) k++; 
                        while(k<l && nums[l] == nums[l+1]) l--; 
                    } else if(sum<target) k++; 
                    else l--; 
                }
                
            }
        }
        return ans; 
    }
};
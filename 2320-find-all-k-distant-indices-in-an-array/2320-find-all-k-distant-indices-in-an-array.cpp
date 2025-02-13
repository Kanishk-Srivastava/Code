class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans; 
        vector<int> keyIndices; 
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == key){
                keyIndices.push_back(i); 
            }
        }
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<keyIndices.size(); ++j){
                if(abs(i-keyIndices[j]) <= k){
                    ans.push_back(i); 
                    break; //as only at least one index is needed. 
                }
            }
        }
        sort(ans.begin(), ans.end()); 
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); 
        return ans; 
    }
};
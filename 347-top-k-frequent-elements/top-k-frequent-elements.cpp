class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        vector<vector<int>> bucket(nums.size() + 1); 
        for(auto num : nums){
            mp[num]++; 
        }

        for(auto &entry:mp){
            int frequency = entry.second; 
            int element = entry.first; 
            bucket[frequency].push_back(element);
        }
        vector<int> result; 
        for(int i=bucket.size() - 1; i>=0 && result.size() < k; i--){
            for(auto num:bucket[i]){
                result.push_back(num);
            }
        }
    return result; 

    }
};
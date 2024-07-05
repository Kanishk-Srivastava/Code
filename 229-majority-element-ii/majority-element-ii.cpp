class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //using hashmap
        vector<int> ans;
        unordered_map<int,int> countMap; 

        for(int i=0;i<nums.size(); i++){
            countMap[nums[i]]++;
        }

        for(auto i : countMap){
            if(i.second > (nums.size()/3)){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
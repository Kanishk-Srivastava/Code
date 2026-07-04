class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll=0; 
        for(int i=0; i<nums.size(); i++){
            xorAll ^= nums[i]; 
        }

        long long diffBit = xorAll & -xorAll; 
        int a=0,b=0; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & diffBit){
                a ^= nums[i]; 
            } else b ^= nums[i]; 
        }

        return {a,b};
    }
};
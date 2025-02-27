class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size()); 
        result[0] = 1; 

        for(int i=1; i<nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }

        int rightProduct = 1; 

        for(int i=nums.size() - 1; i>=0; i--){
            result[i] = result[i] * rightProduct; 
            rightProduct *= nums[i]; 
        }

        return result; 
    }
};
/*
[1,1,1,1]
[1,1,1,1]

[1,2,3,4]


pp [1,1,2,6]

sp [24,12,4,1]

result [24,12,8,6]

i=2
*/
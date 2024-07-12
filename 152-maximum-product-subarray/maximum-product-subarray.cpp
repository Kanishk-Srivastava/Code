class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefixProd = 1, suffixProd = 1; 
        double maxProd = INT_MIN; 

        for(int i=0; i<nums.size(); i++){
            if(prefixProd == 0){
                prefixProd = 1; 
            }
            if(suffixProd == 0){
                suffixProd = 1;
            }
            prefixProd *= nums[i]; 
            suffixProd *= nums[nums.size() - i - 1]; 
            maxProd = max(maxProd, max(prefixProd, suffixProd));
        }
        return maxProd; 
    }
};
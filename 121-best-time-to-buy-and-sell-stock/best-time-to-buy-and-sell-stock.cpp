class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int potentialProfit=0, maxProfit=0; 
        if(prices.size() <=0) return 0; //edge case 
        int minPrice = prices[0]; 

        for(int i=1; i<prices.size(); i++){
            if(prices[i]<minPrice){
                minPrice = prices[i]; 
            } else {
                potentialProfit = prices[i] - minPrice; 
            }
            if(potentialProfit > maxProfit){
                maxProfit = potentialProfit; 
            }
        }

        return maxProfit;    
    }
};
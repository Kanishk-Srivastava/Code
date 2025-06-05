class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; 
        int price = 0; 
        int maxProfit = 0;

        for(int i=0; i<prices.size(); i++){
            minPrice = min(prices[i], minPrice); 
            int profit = prices[i] - minPrice; 
            maxProfit = max(profit, maxProfit); 
        }
        return maxProfit; 
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currSum = 0, minSum = 0; 
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0); 
        int n = cardPoints.size(); 
        int windowSize = n - k; 

        for(int i=0; i<windowSize; i++){
            currSum += cardPoints[i]; 
        }    

        minSum = currSum; 

        for(int i=windowSize; i<n; i++){
            currSum += cardPoints[i] - cardPoints[i - windowSize]; 
            minSum = min(currSum, minSum); 
        }

        return total - minSum; 
    }
};
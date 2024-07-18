class Solution {
public:
    int findDays(vector<int>& weights, int capacity){
        int day = 1; 
        int weight = 0; 

        for(int i=0; i<weights.size(); i++){
            if(weight + weights[i] > capacity){
                day++; 
                weight = weights[i]; 
            } else {
                weight +=weights[i]; 
            }
        }
        return day; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeights = *max_element(weights.begin(), weights.end()); 
        int sumWeights = accumulate(weights.begin(), weights.end(), 0);

        while(maxWeights <= sumWeights){
            int capacity = maxWeights + (sumWeights-maxWeights)/2; 
            int numberOfDays = findDays(weights, capacity);
            if(numberOfDays <= days){
                sumWeights = capacity - 1; 
            } else {
                maxWeights = capacity + 1; 
            }
        }
        return maxWeights; 
    }
};
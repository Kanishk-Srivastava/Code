class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0); 

        while(low<=high){
            int mid = low + (high - low)/2; 

            if(canShip(mid, weights, days)){
                high = mid - 1;
            } else low = mid + 1; 
        }

        return low; 
    }

    bool canShip(int capacity, vector<int> weights, int days){
        int usedDays = 1; 
        int currentLoad = 0;
        
        for(int i=0; i<weights.size(); i++){
            if(currentLoad + weights[i] <= capacity){
                currentLoad += weights[i]; 
            } else {
                usedDays++; 
                currentLoad = weights[i];
            }
        }

        return usedDays <= days;
    }
};
class Solution {
public:
    int findDays(vector<int>& weights, int mid){
        int day = 1; 
        int weight = 0; 

        for(int i=0; i<weights.size(); i++){
            if(weight + weights[i] > mid){
                day++; 
                weight = weights[i]; 
            } else {
                weight +=weights[i]; 
            }
        }
        return day; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left <= right){
            int mid = left + (right-left)/2; 
            int numberOfDays = findDays(weights, mid);
            if(numberOfDays <= days){
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return left; 
    }
};
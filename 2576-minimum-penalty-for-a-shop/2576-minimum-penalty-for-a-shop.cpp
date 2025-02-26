class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = count(customers.begin(), customers.end(), 'Y'); 
        int minHour = 0; 
        int minPenalty = penalty; 

        for(int i=0; i<customers.size(); i++){
            if(customers[i] == 'Y'){
                penalty--; 
            } else {
                penalty++; 
            }

            if(penalty < minPenalty){
                minPenalty = penalty; 
                minHour = i+1; 
            }
        }
        return minHour;
    }
};
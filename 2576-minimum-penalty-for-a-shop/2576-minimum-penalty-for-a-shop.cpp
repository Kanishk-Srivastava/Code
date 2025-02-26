class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
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
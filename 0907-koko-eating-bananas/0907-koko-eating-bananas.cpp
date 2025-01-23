class Solution {
public:

    int findHoursTaken(vector<int>& piles, int mid){
        long long hours = 0; 
        for(int i=0; i<piles.size(); i++){
            hours += ceil((double)piles[i]/mid); 
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left) / 2; 
            int hoursTaken = 0; 
            hoursTaken = findHoursTaken(piles, mid); 
            if(hoursTaken > h){
                left = mid + 1;
            } else {
                right = mid; 
            }
        }
        return left; 
    }
};
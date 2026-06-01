class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1; 
        int low = *min_element(bloomDay.begin(), bloomDay.end()); 
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans = -1; 
        while(low<=high){
            int mid = low + (high - low)/2; 

            if(canMake(bloomDay, mid, m, k)){
                ans = mid; 
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }

        return ans; 
    }

    bool canMake(vector<int>& bloomDay, int mid, int m, int k){
        int bloomCount=0; 
        int bloomed = 0; 
        for(int i=0; i<bloomDay.size(); i++){
            int currDay = bloomDay[i]; 

            if(currDay <= mid){
                bloomCount++; 
                if(bloomCount == k){
                    bloomed++; 
                    bloomCount = 0; 
                }
            } else{
                bloomCount = 0; 
            }
        }
        return (bloomed >= m); 
    }
}; 
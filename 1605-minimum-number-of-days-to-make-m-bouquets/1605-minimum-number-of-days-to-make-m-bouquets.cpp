class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end()); 
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans=-1;
        while(low<=high){
            int mid = low + (high - low) / 2; 
            if(canMake(bloomDay, mid, m, k)) {
                ans = mid; 
                high = mid - 1; 
            } else low = mid + 1; 
        }
        return ans; 
    }

    bool canMake(vector<int>& bloomDay, int mid, int m, int k){
        int flowers = 0, bouquets = 0; 
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
            flowers++; 
                if(flowers == k) {
                    bouquets++; 
                    flowers = 0; 
                }
            } else {
                flowers = 0; 
            }
        }
        return bouquets >= m; 
    }
};
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = *min_element(bloomDay.begin(), bloomDay.end()); 
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        long long val = (long long) m * (long long) k ; 

        if(val > bloomDay.size()) return -1; 

        while(left <= right){
            int mid = left + (right-left)/2; 
            if(possible(bloomDay, m, k, mid)){
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return left; 
    }

    bool possible(vector<int>&bloomDay, int m, int k, int mid){
        int consecCount = 0, numOfBoq = 0; 
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consecCount++; 
            } else consecCount = 0; 

            if(consecCount == k){
                numOfBoq++; 
                consecCount=0; 
            }
        }
        return (numOfBoq >= m);
    }
};
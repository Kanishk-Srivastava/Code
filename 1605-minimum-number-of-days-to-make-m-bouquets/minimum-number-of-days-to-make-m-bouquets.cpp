class Solution {
public:
    int findMinDay(vector<int>& bloomDay){
        int minDay = INT_MAX; 
        for(int i=0; i<bloomDay.size(); i++){
            minDay = min(minDay, bloomDay[i]);
        }
        return minDay;
    }

    int findMaxDay(vector<int>& bloomDay){
        int maxDay = INT_MIN; 
        for(int i=0; i<bloomDay.size(); i++){
            maxDay = max(maxDay, bloomDay[i]);
        }
        return maxDay; 
    }

    int possible(vector<int>& bloomDay, int mid, int m, int k){
        int bouquetCount = 0; 
        int flowerCount = 0; 

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                flowerCount++; 
            } else {
                bouquetCount += flowerCount/k; 
                flowerCount = 0; 
            }
        }
        bouquetCount += flowerCount/k; 
        return bouquetCount >= m; 
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        /* Find min day and max day. calculate mid 
        iterate through the array and check for each flower will it be bloomed or not, keep a counter according to the number of bouquets required and how many adjacent flowers are needed. Also check for m*k > size then return -1.
        */
        int left = findMinDay(bloomDay); 
        int right = findMaxDay(bloomDay); 
        long long val = (long long) m * (long long) k;
        if(val > bloomDay.size()){
            return -1; //edge case 
        }

        while(left <= right){
            int mid = left + (right - left)/2; 
            if(possible(bloomDay, mid, m, k)){
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return left; 
    }
};
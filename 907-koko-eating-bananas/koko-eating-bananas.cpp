class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            if(calcK(piles, mid, h)){
                right = mid;
            }else{
                left = mid + 1;
            }
        } 
        return left;
    }
   

    int calcK(const vector<int>& piles, int mid, int h){
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += ceil((double)piles[i] / mid);
        }
        return ans <= h;
    }
};
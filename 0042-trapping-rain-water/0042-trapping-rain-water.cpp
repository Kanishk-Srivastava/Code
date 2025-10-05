class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1; 
        int lmax = 0, rmax = 0, ans = 0; 
        while(left < right){
            if(height[left] <= height[right]){
                if(lmax > height[left]){
                    ans += lmax - height[left]; 
                } else lmax = height[left]; 
                left++; 
            } else{
                if(rmax > height[right]){
                    ans += rmax - height[right]; 
                } else rmax = height[right]; 
                right--; 
            }
        }
        return ans; 
    }
};
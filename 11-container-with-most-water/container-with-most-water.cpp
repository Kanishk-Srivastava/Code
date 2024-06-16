class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1; 
        int area = 0;
        while(l<r){
            int heightt = min(height[l], height[r]); 
            int lenght = r-l; 
            area =  max(area, heightt * lenght); 
            if(height[l]<height[r]){
                l++; 
            } else {
                r--;
            }
        }
        return area; 
    }
};
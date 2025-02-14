class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN; 
        int l = 0; 
        int r = height.size() - 1; 

        while(l<r){
            int length = min(height[l], height[r]); 
            int width = r - l; 
            area = max(area, length*width); 

            if(height[l]<height[r]){
                l++; 
            } else r--; 
        }
        return area; 
    }
};
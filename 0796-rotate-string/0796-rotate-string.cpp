class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false; 

        int n = s.size(); 

        for(int shift = 0; shift<n; shift++){
            string rotated = ""; 

            for(int i=0; i<n; i++){
                rotated += s[(shift + i) % n]; 
            }

            if(rotated == goal) return true; 
        }

        return false; 
    }
};
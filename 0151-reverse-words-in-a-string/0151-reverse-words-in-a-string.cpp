class Solution {
public:
    string reverseWords(string s) {
        int i=0, left = 0, right =0, n=s.size(); 
        reverse(s.begin(), s.end()); 
        while(i<n){
            while(i<n && s[i] == ' '){
                i++; 
            }
            if(i==n){
                break; 
            }
            while(i<n && s[i] != ' '){
                s[right] = s[i]; 
                right++, i++; 
            }
            reverse(s.begin() + left, s.begin() + right); 
            s[right] = ' '; 
            right++; 
            left = right;
            i++;  
        }
        s.resize(right-1); 
        return s; 
    }
};
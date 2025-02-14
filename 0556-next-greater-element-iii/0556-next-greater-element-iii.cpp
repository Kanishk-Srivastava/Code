class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int idx = -1;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int i = digits.size() - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1; 
        for (int i = digits.size() - 1; i >= idx; i--) {
            if (digits[i] > digits[idx]) {
                swap(digits[i], digits[idx]);
                break;
            }
        }
        reverse(digits.begin() + idx + 1, digits.end());
        long long ans=0;
        for(int i=0; i<digits.size(); i++){
            ans = ans*10 + digits[i]; 
            if(ans>INT_MAX) return -1; 
        }
        return ans;
    }
};
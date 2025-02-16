class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), INT_MAX);
        int idx = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                idx = i;
            }
            if (idx != -1) {
                ans[i] = abs(idx - i);
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c) {
                idx = i;
            }
            if (idx != -1) {
                ans[i] = min(abs(idx - i), ans[i]);
            }
        }
        return ans;
    }
};
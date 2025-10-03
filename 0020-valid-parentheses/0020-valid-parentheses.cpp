class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool valid = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                st.pop();
                if (ch == '(' && s[i] != ')' || ch == '[' && s[i] != ']' ||
                    ch == '{' && s[i] != '}') {
                    return false;
                }
            }
        }
        return st.empty(); 
    }
};
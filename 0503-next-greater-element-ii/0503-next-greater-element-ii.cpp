class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(); 
        vector<int> result(n,-1);

        for (int i = 2 * n- 1; i >= 0; i--) {
            int curr = nums[i % n];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            if (i < n) {
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(curr);
        }
        return result; 
    }
};
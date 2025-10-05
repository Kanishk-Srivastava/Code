class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater; 
        stack<int> st; 
        vector<int> result; 

        for(int i=nums2.size() - 1; i>=0; i--){
            int curr = nums2[i]; 

            while(!st.empty() && st.top() <= curr){
                st.pop(); 
            }

            int greater = st.empty() ? -1 : st.top(); 

            nextGreater[curr] = greater; 
            st.push(curr); 
        }

        for(auto num : nums1){
            result.push_back(nextGreater[num]); 
        }

        return result; 

    }
};
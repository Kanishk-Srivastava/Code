class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater; 
        stack<int> st; 
        vector<int> ans; 

        for(int i=nums2.size()-1; i>=0; i--){
            int curr = nums2[i]; 

            while(!st.empty() && curr >= st.top()){
                st.pop(); 
            }

            if(st.empty()){
                nextGreater[curr] = -1;
            } else {
                nextGreater[curr] = st.top(); 
            }

            st.push(curr); 
        }

        for(int num : nums1){
            ans.push_back(nextGreater[num]);
        }

        return ans; 
    }
};
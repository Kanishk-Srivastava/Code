class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mp[2005] = {};
        for(auto x: arr) mp[x]++;
        int cnt = 0, ans;
        for(int i=1; i<2005; i++) {
            if(!mp[i]) cnt++;
            if(cnt == k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
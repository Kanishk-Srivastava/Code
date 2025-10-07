#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> PSE(n), NSE(n); 
        stack<int> st1,st2;  
        for(int i=0; i<n; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop(); 
            }
            PSE[i] = st1.empty() ? i + 1 : i - st1.top(); 
            st1.push(i); 
        }

        for(int i = n - 1; i>= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop(); 
            }
            NSE[i] = st2.empty() ? n - i : st2.top() - i; 
            st2.push(i); 
        }

        long long sum = 0; 

        for(int i=0; i<n; i++){
            long long contribution = (1LL * NSE[i] * PSE[i] * arr[i]); 
            sum = (sum + contribution) % MOD; 
        }

        return (int) sum; 
    }
};
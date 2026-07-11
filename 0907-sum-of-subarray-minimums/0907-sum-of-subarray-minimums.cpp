#define MOD 1000000007
class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> PSE(n), NSE(n); 
        long sum = 0; 
        stack<int> st1, st2; 

        for(int i=0; i<arr.size(); i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop(); 
            }

            if(st1.empty()){
                PSE[i] = i+1; 
            } else {
                PSE[i] = i - st1.top(); 
            }

            st1.push(i); 
        }

        for(int i=arr.size() - 1; i>=0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop(); 
            }

            if(st2.empty()){
                NSE[i] = arr.size() - i; 
            } else {
                NSE[i] = st2.top() - i; 
            }
            st2.push(i); 
        }

        for(int i=0; i<arr.size(); i++){
            long long contribution = (1LL * NSE[i] * PSE[i] * arr[i]); 
            sum = (sum + contribution) % MOD; 
        }

        return (int) sum; 
    }
};
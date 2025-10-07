class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums); 
        long long minSum = sumSubarrayMins(nums); 
        long long ans = maxSum - minSum; 
        return ans; 
    }

    long long sumSubarrayMaxs(vector<int>& nums){
        int n = nums.size(); 
        vector<int> NGE(n), PGE(n); 
        stack<int> st1, st2; 

        for(int i = 0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] <= nums[i]){
                st1.pop(); 
            }
            PGE[i] = st1.empty() ? i+1 : i - st1.top(); 
            st1.push(i); 
        }

        for(int i = n - 1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                st2.pop(); 
            }
            NGE[i] = st2.empty() ? n - i : st2.top() - i; 
            st2.push(i); 
        }

        long long sum = 0; 

        for(int i = 0; i<n; i++){
            long long contribution = (1LL * NGE[i] * PGE[i] * nums[i]); 
            sum += contribution; 
        }

        return sum; 
    }

    long long sumSubarrayMins(vector<int>& nums){
        int n = nums.size(); 
        vector<int> NSE(n), PSE(n); 
        stack<int> st1, st2; 

        for(int i = 0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] >= nums[i]){
                st1.pop(); 
            }
            PSE[i] = st1.empty() ? i+1 : i - st1.top(); 
            st1.push(i); 
        }

        for(int i = n - 1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] > nums[i]){
                st2.pop(); 
            }
            NSE[i] = st2.empty() ? n - i : st2.top() - i; 
            st2.push(i); 
        }

        long long sum = 0; 

        for(int i = 0; i<n; i++){
            long long contribution = (1LL * NSE[i] * PSE[i] * nums[i]); 
            sum += contribution; 
        }

        return sum; 
        
    }
};
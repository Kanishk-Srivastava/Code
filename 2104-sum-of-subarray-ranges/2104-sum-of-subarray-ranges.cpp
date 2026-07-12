class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long max = subMax(nums); 
        long long min = subMin(nums); 
        long long ans = max - min; 
        return ans; 
    }

    long long subMax(vector<int>& nums){
        stack<long long> st1, st2; 
        long long sum = 0;
        int n = nums.size();  
        vector<int> PGE(n), NGE(n); 
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] <= nums[i]){
                st1.pop(); 
            }

            if(st1.empty()){
                PGE[i] = i+1; 
            } else {
                PGE[i] = i - st1.top(); 
            }
            st1.push(i);
        }

        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                st2.pop();
            }

            if(st2.empty()){
                NGE[i] = n-i; 
            } else {
                NGE[i] = st2.top() - i; 
            }
            st2.push(i);
        }

        for(int i=0; i<n; i++){
            long long contribution = (1LL * PGE[i] * NGE[i] * nums[i]); 
            sum += contribution; 
        }
        return sum; 
    }

        long long subMin(vector<int>& nums){
        stack<long long> st1, st2; 
        long long sum = 0;
        int n = nums.size();  
        vector<int> PSE(n), NSE(n); 
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] >= nums[i]){
                st1.pop(); 
            }

            if(st1.empty()){
                PSE[i] = i+1; 
            } else {
                PSE[i] = i - st1.top(); 
            }
            st1.push(i);
        }

        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] > nums[i]){
                st2.pop();
            }

            if(st2.empty()){
                NSE[i] = n-i; 
            } else {
                NSE[i] = st2.top() - i; 
            }
            st2.push(i);
        }

        for(int i=0; i<n; i++){
            long long contribution = (1LL * PSE[i] * NSE[i] * nums[i]); 
            sum += contribution; 
        }
        return sum; 
    }

};
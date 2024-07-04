class Solution {
public:
    void merge(vector<int>& count, vector<pair<int,int>>& numsPair, int low, int mid,  int high){
        vector<pair<int,int>> temp(high-low+1); 
        int i=low; 
        int j = mid+1; 
        int k=0; 
        while(i<=mid and j<=high){
            if(numsPair[i].first <= numsPair[j].first){
                temp[k++] = numsPair[j++];
            } else {
                //increment the number of elements smaller than that element at that elements index. 
                count[numsPair[i].second] += high - j + 1; 
                temp[k++] = numsPair[i++]; 
            }
        }

          while(i<=mid){
                temp[k++] = numsPair[i++];
            }
            while(j<=high){
                temp[k++] = numsPair[j++];
            }
            for(int i=low; i<=high; i++){
                numsPair[i] = temp[i-low]; 
            }
    }

    void mergeSort(vector<int>& count, vector<pair<int,int>>& numsPair, int low, int high){
        if(low<high){
            int mid = low+(high-low)/2;
            mergeSort(count, numsPair, low, mid); 
            mergeSort(count, numsPair, mid+1, high);
            merge(count, numsPair, low, mid, high);
        }

    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size(); 
        vector<pair<int,int>> numsPair; 
        for(int i=0; i<n; i++){
            numsPair.push_back({nums[i], i}); //push the number and its index
        }
        vector<int>ans(n,0); 
        mergeSort(ans, numsPair, 0, n-1); 
        return ans; 
    }
};
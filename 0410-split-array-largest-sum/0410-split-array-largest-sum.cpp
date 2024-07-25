class Solution {
public:

int findStudent(vector<int>& arr, int pages){
    int student = 1, pagesStudent = 0; 
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i]; 
        } else {
            student++; 
            pagesStudent = arr[i]; 
        }
    }
    return student; 
}

int findPages(vector<int>& arr, int n, int m) {
    if(arr.size() < m){
        return -1; 
    }
    int left = *max_element(arr.begin(), arr.end()); 
    int right = accumulate(arr.begin(), arr.end(), 0); 

    while(left <= right){
        int pages = left + (right - left)/2; 
        int student = findStudent(arr, pages); 
        if(student <= m){
            right = pages - 1; 
        } else {
            left = pages + 1; 
        }
    }
    return left; 
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};
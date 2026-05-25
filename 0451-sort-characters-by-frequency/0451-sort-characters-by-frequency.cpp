class Solution {
public:
    typedef pair<char,int> P; 
    string frequencySort(string s) {
        vector<P> vec(123); 
        string result; 

        for(char ch : s){
            int freq = vec[ch].second; 
            vec[ch] = {ch, freq+1}; 
        }

        auto lambda = [&](P &p1, P &p2){
            return p1.second > p2.second;
        }; 

        sort(vec.begin(), vec.end(), lambda);
        for(int i=0; i<vec.size(); i++){
            int freq = vec[i].second; 
            char ch = vec[i].first; 

            string temp = string(freq, ch); 
            result += temp; 
        }

        return result; 
    }
};
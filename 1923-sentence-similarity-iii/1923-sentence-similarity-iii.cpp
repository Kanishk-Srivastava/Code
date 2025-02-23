class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.size() < s2.size()) {
            swap(s1, s2); // s1 will always be the longer sentence
        }
        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;

        while (ss1 >> token) {
            vec1.push_back(token);
        }

        stringstream ss2(s2);
        while (ss2 >> token) {
            vec2.push_back(token);
        }

        int i = 0, k = 0;
        int j = vec1.size() - 1, l = vec2.size() - 1;

        while (k < vec2.size() && i < vec1.size() && vec1[i] == vec2[k]) {
            i++, k++;
        }

        while (l >= k && vec1[j] == vec2[l]) {
            l--, j--;
        }

        return l < k;
    }
};
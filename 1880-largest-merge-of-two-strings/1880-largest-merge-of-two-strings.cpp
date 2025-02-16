class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string merge = "";

        while (i < word1.size() && j < word2.size()) {
            // Compare remaining substrings directly using iterators (O(1) per
            // comparison)
            if (lexicographical_compare(word1.begin() + i, word1.end(),
                                        word2.begin() + j, word2.end())) {
                merge.push_back(word2[j++]); // Take from word2 if it's
                                             // lexicographically larger
            } else {
                merge.push_back(word1[i++]); // Otherwise, take from word1
            }
        }

        // Append remaining characters from word1 or word2
        merge.append(word1.substr(i));
        merge.append(word2.substr(j));

        return merge;
    }
};
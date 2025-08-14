class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Always binary search the smaller array
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size(), n = B.size();
        int totalLeft = (m + n + 1) / 2; // Size of the left half

        int lo = 0, hi = m; // search range in A
        while (lo <= hi) {
            int cutA = (lo + hi) / 2;           // pick some from A
            int cutB = totalLeft - cutA;        // rest from B

            int Aleft  = (cutA == 0) ? INT_MIN : A[cutA - 1];
            int Aright = (cutA == m) ? INT_MAX : A[cutA];
            int Bleft  = (cutB == 0) ? INT_MIN : B[cutB - 1];
            int Bright = (cutB == n) ? INT_MAX : B[cutB];

            // Perfect partition found
            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) { 
                    // Odd total → median is max of left side
                    return max(Aleft, Bleft);
                }
                // Even total → average of max(left) and min(right)
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            // Too many from A → move cutA left
            else if (Aleft > Bright) {
                hi = cutA - 1;
            }
            // Too few from A → move cutA right
            else {
                lo = cutA + 1;
            }
        }
        return 0.0; // Should not reach here for valid input
    }
};

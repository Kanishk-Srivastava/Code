class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0, r = plants.size() - 1;
        int refill = 0;
        int originalCapA = capacityA;
        int originalCapB = capacityB;
        while (l <= r) {
            if (l == r) {
                if (capacityA >= capacityB) {
                    if (capacityA < plants[l]) {
                        refill++;
                    }
                    l++;
                } else {
                    if (capacityB < plants[r]) {
                        refill++;
                    }
                    r--;
                }
            } else {
                if (capacityA < plants[l]) {
                    refill++;
                    capacityA = originalCapA;
                }
                capacityA -= plants[l];
                l++;

                if (capacityB < plants[r]) {
                    refill++;
                    capacityB = originalCapB;
                }
                capacityB -= plants[r];
                r--;
            }
        }
        return refill;
    }
};
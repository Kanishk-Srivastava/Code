class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        if (b == 0) return 1;
        long long half = power(a, b / 2);
        long long result = (half * half) % MOD;
        if (b % 2) result = (result * a) % MOD;
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // even positions
        long long odd  = n / 2;       // odd positions
        return (power(5, even) * power(4, odd)) % MOD;
    }
};

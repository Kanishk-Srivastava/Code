// RECURSIVE
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        i = skipSpaces(s, i, n);

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long result = parseDigits(s, i, sign, 0);

        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;

        return (int)result;
    }

    int skipSpaces(string& s, int i, int n) {
        if (i < n && s[i] == ' ')
            return skipSpaces(s, i + 1, n);
        return i;
    }

    long parseDigits(string& s, int i, int sign, long result) {
        if (i >= s.size() || !isdigit(s[i]))
            return sign * result;

        int digit = s[i] - '0';
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;

        return parseDigits(s, i + 1, sign, result);
    }
};

/* ITERATVIE
class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();

        while(i<n && s[i] == ' ') i++;

        int sign = 1;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        long result = 0;

        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';

            if(result > (INT_MAX - digit) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            i++;
        }

        return (int)(sign * result);
    }
};
*/
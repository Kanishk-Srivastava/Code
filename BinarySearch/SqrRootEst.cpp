#include <iostream>
using namespace std;

int square_root(int n) {
    if (n == 0) return 0;
    int left = 1, right = n, res = -1;
    //left=1 right = 16
    while (left <= right) {
        int mid = left + (right - left) / 2;
        //mid = 8
        //mid = 4
        if (mid == n / mid) {
            //16 == 15/8? false
            //4 == 15/4? false
            return mid;
        } else if (mid * mid > n) {
            //8*8 > 15? true
            right = mid - 1;
            //right = 7
            res = mid;
            //res = 8
        } else {
            left = mid + 1;
        }
    }
    return res - 1;
}

int main()
{
    int n;
    cin >> n;
    int ans =  square_root(n);
    cout << ans;    
}

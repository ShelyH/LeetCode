
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x > 0)) {
            return false;
        }
        int y = x;
        int b = 0;
        while (y > b) {
            b = b * 10 + y % 10;
            y /= 10;
        }
        // cout << b << endl;
        return x / 10 == b || b == x;
    }
};

int main()
{
    Solution s;
    // 2147483647
    int x = 12121;
    bool res = s.isPalindrome(x);
    cout << res << endl;

    system("pause");
    return 0;
}

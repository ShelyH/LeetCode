
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        if (n == 0) {
            return 1;
        }
        if (n > 0) {
            if (n % 2 == 0) {
                return myPow(x * x, n / 2);
            }
            else {
                return x * myPow(x * x, (n - 1) / 2);
            }
        }
        else {
            return 1 / x * myPow(1 / x, -(n + 1));
        }
    }
};

int main()
{
    Solution s;
    double res = s.myPow(2, 2);
    cout << res;
    system("pause");
    return 0;
}

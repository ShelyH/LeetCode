
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int n = 0;
        while (x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n > INT_MAX || n < INT_MIN ? 0 : n;
    }
};

int main()
{
    int x = -101000011;
    Solution s;
    int n = s.reverse(x);
    cout << n << endl;

    system("pause");
    return 0;
}

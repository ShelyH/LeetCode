#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i - 1; j++) {
                dp[i] = max(dp[i], max(dp[i - j]*j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    Solution s;
    int res = s.integerBreak(10);
    cout << res << endl;
    return 0;
}

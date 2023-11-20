#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        // vector<int> dp(cost.size()+1);
        int dp0 = 0;
        int dp1 = 0;
        int sum = 0;
        for (int i = 2; i <= cost.size(); i++) {
            sum = min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
            dp0 = dp1;
            dp1 = sum;
        }
        return dp1;
    }
};

int main(int argc, char const* argv[])
{
    Solution s;
    vector<int> cost = {10, 15, 20};
    int res = s.minCostClimbingStairs(cost);
    cout << res << endl;
    /* code */
    return 0;
}

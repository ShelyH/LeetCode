
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n)
    {
        traversal(k, n, 1, 0);
        return res;
    }

    void traversal(int k, int n, int startIndex, int sum)
    {
        if (path.size() == k) {
            for (auto i : path) {
                sum += i;
            }
            if (sum == n) {
                res.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            path.push_back(i);
            traversal(k, n, i + 1, sum);
            path.pop_back();
            int sum = 0;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.combinationSum3(3, 7);

    system("pause");
    return 0;
}

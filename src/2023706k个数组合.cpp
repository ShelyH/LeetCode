
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {
        traversal(n, k, 1);
        return res;
    }

    void traversal(int n, int k, int startIndex)
    {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        int end = n;
        for (int i = startIndex; i <= end; i++) {
            path.push_back(i);
            traversal(n, k, i + 1);
            path.pop_back();  // 回溯
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    system("pause");
    return 0;
}

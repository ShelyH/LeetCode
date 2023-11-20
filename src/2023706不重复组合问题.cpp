#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /// <summary>

    /// </summary>
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<bool> used(candidates.size(), false);
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        traversal(candidates, target, 0, 0, used);
        return res;
    }

    void traversal(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used)
    {
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }

            used[i] = true;
            path.push_back(candidates[i]);
            sum += candidates[i];
            traversal(candidates, target, sum, i + 1, used);
            sum -= candidates[i];  // 回溯
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;
    vector<int> val = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum2(val, target);

    system("pause");
    return 0;
}

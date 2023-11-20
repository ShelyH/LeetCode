
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used)
    {
        if (path.size() >= nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> val = {1, 1, 2};
    vector<vector<int>> res = s.permuteUnique(val);

    system("pause");
    return 0;
}

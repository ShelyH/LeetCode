
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int startIndex)
    {
        if (path.size() > 1) {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 7, 6, 7};
    vector<vector<int>> res = s.findSubsequences(nums);
    system("pause");
    return 0;
}

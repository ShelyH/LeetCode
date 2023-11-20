
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums)
    {
        if (nums.empty()) {
            return res;
        }
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int startIndex)
    {
        if (startIndex < nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.subsets(nums);

    system("pause");
    return 0;
}

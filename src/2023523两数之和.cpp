
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> twoSumTarget(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.size() - 1;
        vector<vector<int>> res;

        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo];
            int right = nums[hi];

            if (sum < target) {
                while (lo < hi && nums[lo] == left)
                    lo++;
            }
            else if (sum > target) {
                while (lo < hi && nums[hi] == right)
                    hi--;
            }
            else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left)
                    lo++;
                while (lo < hi && nums[hi] == right)
                    hi--;
            }
            // lo++;/*
            // hi--;*/
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution s;

    vector<vector<int>> arr = s.twoSumTarget(nums, 6);

    for (vector<vector<int>>::iterator it = arr.begin(); it != arr.end(); it++) {
        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = searchleft(nums, target);
        int right = searchright(nums, target);
        if (left < 0 || right < 0) {
            return {-1, -1};
        }
        else if (right - left > 1) {
            return {left + 1, right - 1};
        }
        return {-1, -1};
    }

    // 寻找左区间
    int searchleft(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftbound = -2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftbound = right;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return leftbound;
    }

    // 寻找右区间
    int searchright(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightbound = -2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
                rightbound = left;
            }
        }
        return rightbound;
    }
};

int main()
{
    vector<int> val = {2, 2};
    int tar = 8;
    Solution s;
    vector<int> res = s.searchRange(val, tar);

    system("pause");
    return 0;
}

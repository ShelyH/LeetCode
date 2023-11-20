
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (target < nums[left]) {
            return left;
        }
        else if (target > nums[right]) {
            return right + 1;
        }
        else {
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] >= target) {
                    right = mid - 1;
                }
                else if (nums[mid] < target) {
                    left = mid + 1;
                }
            }
            return left;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 7};
    int tar = 2;
    int res = s.searchInsert(nums, tar);
    system("pause");
    return 0;
}

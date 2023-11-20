
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[idx] = nums[i];
                idx++;
            }
        }

        return idx;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2, 2, 2, 2, 3, 4};

    Solution s;

    int k = s.removeDuplicates(nums);
    for (vector<int>::iterator it = nums.begin(); it != nums.begin() + k; it++) {
        cout << *it << endl;
    }
    // cout << k << endl;
    system("pause");
    return 0;
}

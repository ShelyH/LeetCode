
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};

        if (n < 2 || nums.size() < n) {
            return res;
        }
        else if (n == 2) {
            int left = start;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                int l_num = nums[left];
                int r_num = nums[right];

                if (sum < target) {
                    while (left < right && nums[left] == l_num) {
                        left++;
                    }
                }
                else if (sum > target) {
                    while (left < right && nums[right] == r_num) {
                        right--;
                    }
                }
                else {
                    res.push_back({nums[left], nums[right]});

                    while (left < right && nums[left] == l_num) {
                        left++;
                    }
                    while (left < right && nums[right] == r_num) {
                        right--;
                    }
                }
            }
        }
        else {
            // vector<vector<int>> res;
            for (int i = start; i < nums.size(); i++) {
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& arr : sub) {
                    // (n-1)Sum ���� nums[i] ���� nSum
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    Solution s;

    vector<vector<int>> res = s.nSum(arr, 4, 0, 0);

    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
            cout << *it2 << " ";
        }

        cout << endl;
    }

    system("pause");
    return 0;
}

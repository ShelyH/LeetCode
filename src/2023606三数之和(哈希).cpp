
#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        int m = 0;
        if (nums.size() < 3) {
            return arr;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    arr.push_back({nums[i], nums[j], c});

                    set.erase(c);
                }
                else {
                    set.insert(nums[j]);
                }
            }
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = {1, 2, -2, -1};
    Solution s;
    vector<vector<int>> res = s.threeSum(arr);

    for (vector<vector<int>>::iterator i = res.begin(); i != res.end(); i++) {
        for (vector<int>::iterator it = (*i).begin(); it != (*i).end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

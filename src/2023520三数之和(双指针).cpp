
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> arr;
        // vector<int*> arr;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                // cout << nums[j];
                for (int k = j + 1; k < nums.size(); k++) {
                    // cout << k << endl;
                    // cout << nums[i] << nums[j] << nums[k];
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // cout << nums[i] << endl;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);

                        arr.push_back(temp);
                        // arr.push_back(temp);
                        // arr[m] = nums[i];
                        // arr.push_back(vector<int>(nums[j]));
                        // arr.push_back(vector<int>(nums[k]));
                        // m++;
                        temp.clear();
                        // cout << m;
                    }
                }
            }
        }

        return arr;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        int m = 0;

        if (nums.size() < 3) {
            return arr;
        }

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[0] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    arr.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return arr;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 1, -1, -1};
    Solution2 s;
    vector<vector<int>> arr = s.threeSum(nums);

    for (vector<vector<int>>::iterator it = arr.begin(); it != arr.end(); it++) {
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

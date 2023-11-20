
#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {2, 5};
    vector<int> res = s.intersection(arr1, arr2);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

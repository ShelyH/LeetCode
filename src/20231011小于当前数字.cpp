#include <iostream>
#include <vector>

#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        vector<int> hash(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            hash[vec[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};

int main(int argc, char const* argv[]) {
    /* code */
    Solution s;
    vector<int> v = {8,1,2,2,3};
    vector<int> res = s.smallerNumbersThanCurrent(v);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}

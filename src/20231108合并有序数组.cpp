#include <iostream>
#include <vector>

#include "algorithm"
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n > 0 || m > 0) {
            if (n == 0) {
                return;
            }
            if (m > 0 && nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            } else {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> val1 = {1, 2, 3, 0, 0, 0};
    vector<int> val2 = {1, 2, 3, 0, 0, 0};
    s.merge(val1, 3, val2, 3);
    return 0;
}

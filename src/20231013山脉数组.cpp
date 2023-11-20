#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] > arr[i]) {
                left++;
            } else {
                break;
            }
        }
        // cout << left << endl;
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i - 1] > arr[i]) {
                right--;
            } else {
                break;
            }
        }
        if (left == right && left != 0 && right != arr.size() - 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<int> val = {1, 2, 3, 4, 3, 1};
    Solution s;
    bool res = s.validMountainArray(val);
    cout << res << endl;
    return 0;
}

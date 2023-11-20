#include <iostream>
#include <vector>

#include "algorithm"
#include "math.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int size = digits.size() - 1;
        int cur = 1;
        while (size >= 0 || cur != 0) {
            if (size >= 0) {
                cur += digits[size--];
            }
            int num1 = cur % 10;
            res.push_back(num1);
            cur /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> val = {9};
    vector<int> res = s.plusOne(val);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

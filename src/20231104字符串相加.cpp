#include <iostream>

#include "algorithm"
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int cur = 0;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;
        while (len1 >= 0 || len2 >= 0 || cur > 0) {
            if (len1 >= 0) {
                cur += num1[len1--] - '0';
            }
            if (len2 >= 0) {
                cur += num2[len2--] - '0';
            }
            res += to_string(cur % 10);
            cur /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char const *argv[]) {
    string num1 = "6913259244";
    string num2 = "71103343";
    Solution s;
    string res = s.addStrings(num1, num2);
    cout << res << endl;
    return 0;
}

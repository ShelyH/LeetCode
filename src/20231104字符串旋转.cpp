#include <iostream>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        string res;
        res = s2 + s2;
        string::size_type idx;
        idx = res.find(s1);
        // cout << idx << endl;
        if (idx != string::npos) {
            return true;
        } else {
            return false;
        }

        // int m = s1.size(), n = s2.size();
        // if (m != n) {
        //     return false;
        // }
        // if (m == 0) {
        //     return true;
        // }
        // for (int i = 0; i < m; i++) {
        //     int flag = true;
        //     for (int j = 0; j < m; j++) {
        //         if (s1[j] != s2[(i + j) % m]) {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag) {
        //         return true;
        //     }
        // }
        // return false;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    string val1 = "aa";
    string val2 = "cdab";
    bool res = s.isFlipedString(val1, val2);
    cout << res << endl;
    return 0;
}

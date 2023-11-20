#include <iostream>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (res.size() != 0 && abs(res.back() - s[i]) == 32) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string str = "leEeetcode";
    string res = s.makeGood(str);
    cout << res << endl;
    return 0;
}

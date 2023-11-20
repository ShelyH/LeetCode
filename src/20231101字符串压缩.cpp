#include <iostream>
using namespace std;

class Solution {
public:
    string compressString(string s) {
        int left = 0;
        string res;
        for (left = 0; left < s.size(); ) {
            res.push_back(s[left]);
            int right = 1;
            while (s[left] == s[left+right]) {
                right++;
            }
            res+=to_string(right);
            left+=right;

        }
        if(res.size()>s.size()){
            return s;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    string v = "bb";
    Solution s;
    string res = s.compressString(v);
    cout << res << endl;
    return 0;
}

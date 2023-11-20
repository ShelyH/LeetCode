#include <iostream>
#include <unordered_map>

#include "algorithm"

using namespace std;

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         if (s1.size() > s2.size()) {
//             return false;
//         }
//         int n = s1.size();
//         sort(s1.begin(), s1.end());
//         for (int i = 0; i <= s2.size() - n; i++) {
//             string tmp = s2.substr(i, n);
//             sort(tmp.begin(), tmp.end());
//             if (tmp == s1) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         unordered_map<char, int> need, window;
//         for (char c : s1) {
//             need[c]++;
//         }

//         int left = 0, right = 0;
//         int valid = 0;
//         while (right < s2.size()) {
//             char s = s2[right];
//             right++;
//             if (need.count(s)) {
//                 window[s]++;
//                 if (need[s] == window[s]) {
//                     valid++;
//                 }
//             }

//             while (right - left >= s1.size()) {
//                 if (valid == need.size()) {
//                     return true;
//                 }
//                 char d = s2[left];
//                 left++;
//                 if (need.count(d)) {
//                     if (window[d] == need[d]) {
//                         valid--;
//                     }
//                     window[d]--;
//                 }
//             }
//         }
//         return false;
//     }
// };

 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1length = s1.size();
        int s2length = s2.size();
        if (s1length > s2length) {
            return false;
        }
        unsigned long hash = 0;
        unsigned long hash1 = 0;
         for (int i = 0; i < s1length; i++) {
            hash += ((int)s1[i] * (int)s1[i]) * 7;
            hash1 += ((int)s2[i] * (int)s2[i]) * 7;
        }
        int left = 0;
        int right = s1length - 1;
        while (right < s2length) {
            if (hash1 == hash) {
                return true;
            }
            hash1 -= (((int)s2[left] * (int)s2[left]) * 7);
            right++;
            left++;
            hash1 += (((int)s2[right] * (int)s2[right]) * 7);
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string s1 = "aa";
    string s2 = "babaaedfg";
    bool res = s.checkInclusion(s1, s2);
    cout << res << endl;
    return 0;
}

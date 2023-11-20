
#include <iostream>
using namespace std;

class Solution {
public:
    string Palindrome(string s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }

        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s)
    {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            string res1 = Palindrome(s, i, i);
            string res2 = Palindrome(s, i, i + 1);

            res = res.length() > res1.length() ? res : res1;
            res = res.length() > res2.length() ? res : res2;
        }

        return res;
    }
};

int main()
{
    string s = "babad";

    Solution so;
    string res = so.longestPalindrome(s);
    cout << res << endl;

    system("pause");
    return 0;
}

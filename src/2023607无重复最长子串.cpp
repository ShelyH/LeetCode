
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int hashmap[130] = {0};
        int n = s.size();
        int max = 0;
        int i = 0;
        string sub;
        for (int j = 0; j < n; j++) {
            hashmap[s[j]]++;
            while (hashmap[s[j]] > 1) {
                hashmap[s[i++]]--;
            }
            if (j - i + 1 > max) {
                max = j - i + 1;
                sub = s.substr(i, max);
            }
        }
        cout << sub << endl;
        return max;
    }
};

int main()
{
    string s = "abcdeabcdefga";
    Solution so;
    int max = so.lengthOfLongestSubstring(s);
    cout << max << endl;

    system("pause");
    return 0;
}


#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main()
{
    vector<char> s = {'a', 'b', 'c', 'e', '1'};

    Solution so;
    so.reverseString(s);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}

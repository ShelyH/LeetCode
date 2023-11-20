#include <iostream>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int nameSize = name.size();
        int typedSize = typed.size();
        if (typedSize < nameSize) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < nameSize && j < typedSize) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }
            else {
                return false;
            }
        }
        while (j < typedSize) {
            if (typed[j] != typed[j - 1]) {
                return false;
            }
            j++;
        }
        if (i == nameSize && j <= typedSize) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    Solution s;
    string name = "a";
    string typed = "b";
    bool res = s.isLongPressedName(name, typed);
    cout << res << endl;

    system("pause");
    return 0;
}

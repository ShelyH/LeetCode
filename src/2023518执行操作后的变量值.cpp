
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int X = 0;
        // cout << operations.size() << endl;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "++X") {
                ++X;
            }
            else if (operations[i] == "X++") {
                X++;
            }
            else if (operations[i] == "X--") {
                X--;
            }
            else {
                --X;
            }
        }
        return X;
    }
};

int main()
{
    Solution s;
    vector<string> operations = {"++X", "X++", "X++"};
    int x = s.finalValueAfterOperations(operations);
    cout << x << endl;

    system("pause");
    return 0;
}

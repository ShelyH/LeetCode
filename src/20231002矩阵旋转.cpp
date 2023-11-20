#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < len; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < len / 2; j++) {
                int tmp = matrix[i][j];
                // cout<<tmp<<endl;
                matrix[i][j] = matrix[i][len - j - 1];
                matrix[i][len - j - 1] = tmp;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < len; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> ma = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(ma);
    /* code */
    return 0;
}

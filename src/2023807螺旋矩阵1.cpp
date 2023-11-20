
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int count = 1;
        int offset = 1;
        int loop = n / 2;
        int mid = n / 2;
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            // 左到右
            for (; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 上到下
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 右到左
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 下到上
            for (; i > startx; i--) {
                res[i][starty] = count++;
            }

            startx++;
            starty++;
            offset++;
        }
        if (n % 2 == 1) {
            res[mid][mid] = n ^ 2;
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(3);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    // cout
    // system("pause");
    return 0;
}

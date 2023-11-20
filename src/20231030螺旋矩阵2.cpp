#include <iostream>
using namespace std;
#include <vector>

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        int minx = 0, maxx = m - 1;
        int miny = 0, maxy = n - 1;
        int i = minx;
        int j = -1;
        int cnt = 0;
        int lim = m * n;
        int drc = 0;
        while (cnt < lim) {
            if (drc == 0) {
                while (j < maxy) {
                    j++;
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
                drc++;
                minx++;
            } else if (drc == 1) {
                while (i < maxx) {
                    i++;
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
                drc++;
                maxy--;
            } else if (drc == 2) {
                while (j > miny) {
                    j--;
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
                drc++;
                maxx--;
            } else {
                while (i > minx) {
                    i--;
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
                drc = 0;
                miny++;
            }
        }
        return res;
    }
};
 
class Solution {
private:
    const vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size();
        int columns = matrix[0].size();
        int total = rows * columns;
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        vector<int> order(total);

        int row = 0;
        int column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            } 
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    vector<int> res = s.spiralOrder(v);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

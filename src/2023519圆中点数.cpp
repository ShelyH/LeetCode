
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> new_arr;
        for (int i = 0; i < queries.size(); i++) {
            int q_x = queries[i][0];
            int q_y = queries[i][1];
            int r = queries[i][2];

            int count = 0;
            for (int j = 0; j < points.size(); j++) {
                int p_x = points[j][0];
                int p_y = points[j][1];
                int dis = (q_x - p_x) * (q_x - p_x) + (q_y - p_y) * (q_y - p_y);
                if (dis <= r * r) {
                    count++;
                }
            }
            new_arr.push_back(count);
        }

        return new_arr;
    }
};

int main()
{
    vector<vector<int>> p = {{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    vector<vector<int>> q = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    Solution s;
    vector<int> arr = s.countPoints(p, q);
    vector<int> ans(5);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}

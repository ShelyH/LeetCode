
#include <iostream>
#include <vector>

#include "algorithm"
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<int> road(1001, 0);
        for (auto it : trips) {
            road[it[1]] += it[0];
            road[it[2]] -= it[0];
        }
        int num = 0;
        for (int i : road) {
            num += i;
            if (num > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;

    bool res = s.carPooling(trips, capacity);

    system("pause");
    return 0;
}

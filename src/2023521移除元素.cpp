
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.size() == 0) {
            return 0;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3};
    Solution s;
    // int size = arr.size();
    int size = s.removeElement(arr, 2);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    system("pause");
    return 0;
}

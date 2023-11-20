
#include <iostream>
using namespace std;
#include <vector>

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        // 初始化数组
        res.resize(nums.size() + 1);
        // 计算累加和
        for (int i = 1; i < res.size(); i++) {
            res[i] = res[i - 1] + nums[i - 1];
        }

        for (auto a : res) {
            cout << a << " ";
        }
        cout << endl;
    }

    /* 查询闭区间 [left, right] 的累加和 */
    int sumRange(int left, int right)
    {
        return res[right + 1] - res[left];
    }

private:
    vector<int> res;
};

// int main()
//{
//	vector<int> nums = { 1,2,3,4 };
//	NumArray arr(nums);
//	int res = arr.sumRange(0, 3);
//	cout << res << endl;
//	system("pause");
//	return 0;
// }

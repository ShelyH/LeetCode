
#include <iostream>
using namespace std;
#include <cassert>

class Diifference {
public:
    Diifference(int* nums, int length)
    {
        this->length = length;
        assert(this->length > 0);
        diff = new int[this->length]();
        diff[0] = nums[0];
        /* 输入一个初始数组，区间操作将在这个数组上进行 */
        for (int i = 1; i < this->length; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
    void increment(int left, int right, int val)
    {
        diff[left] += val;
        if (right + 1 < this->length) {
            diff[right + 1] -= val;
        }
    }

    /* 返回结果数组 */
    int* res()
    {
        int* res = new int[this->length]();
        res[0] = diff[0];
        for (int i = 1; i < this->length; i++) {
            res[i] = diff[i] + res[i - 1];
        }

        return res;
    }

private:
    int* diff;
    int length;
};

int main()
{
    const int length = 5;
    int arr[length] = {1, 2, 3, 4, 2};

    Diifference d(arr, length);
    d.increment(1, 3, 2);

    int* res = d.res();
    for (int i = 0; i < length; i++) {
        cout << res[i] << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}

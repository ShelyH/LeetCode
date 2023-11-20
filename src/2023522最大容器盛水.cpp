
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// class Solution {
// public:
//	int maxArea(vector<int>& height) {
//		int max = 0;
//		int sum;
//		for (int i = 0; i < height.size(); i++)
//		{
//			for (int j = i + 1; j < height.size(); j++)
//			{
//				if (height[i] <= height[j])
//				{
//					sum = height[i] * (j - i);
//					if (sum > max)
//					{
//						max = sum;
//					}
//				}
//				if (height[i] >= height[j])
//				{
//					sum = height[j] * (j - i);
//					if (sum > max)
//					{
//						max = sum;
//					}
//				}
//			}
//		}
//		return max;
//	}
// };

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        int sum = 0;
        int left = 0;

        int right = height.size() - 1;
        while (left < right) {
            sum = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, sum);
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};

// int main()
//{
//	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
//	Solution s;
//	int max = s.maxArea(height);
//	cout << max << endl;
//	system("pause");
//	return 0;
// }

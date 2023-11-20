
#include <iostream>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    // 1.数组
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        TreeNode* node = new TreeNode;
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }

        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;

        if (maxValueIndex > 0) {
            vector<int> leftnums(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(leftnums);
        }

        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> rightnums(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(rightnums);
        }

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        // 2.下标
        if (nums.empty()) {
            return nullptr;
        }
        TreeNode* root = constructMxBtree(nums, 0, nums.size());
        return root;
    }

    TreeNode* constructMxBtree(vector<int>& nums, int left, int right)
    {
        if (left >= right) {
            return nullptr;
        }
        int maxValueIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) {
                maxValueIndex = i;
            }
        }

        TreeNode* node = new TreeNode(nums[maxValueIndex]);

        node->left = constructMxBtree(nums, left, maxValueIndex);
        node->right = constructMxBtree(nums, maxValueIndex + 1, right);

        return node;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution s;
    TreeNode* root = s.constructMaximumBinaryTree(nums);
    system("pause");
    return 0;
}

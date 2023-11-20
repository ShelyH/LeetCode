
#include <iostream>
#include <queue>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    TreeNode* createTree(vector<int> l_nums)
    {
        if (l_nums.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(l_nums[0]);
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;

        while (!que.empty() && i < l_nums.size()) {
            TreeNode* node = que.front();
            que.pop();
            if (l_nums[i] != NULL) {
                node->left = new TreeNode(l_nums[i]);
                que.push(node->left);
            }
            i++;
            if (i < l_nums.size() && l_nums[i] != NULL) {
                node->right = new TreeNode(l_nums[i]);
                que.push(node->right);
            }
            i++;
        }
        return root;
    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int leftValue = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);
        int sum = leftValue + rightValue;
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> val = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* root = s.createTree(val);
    int res = s.sumOfLeftLeaves(root);
    cout << res << endl;

    system("pause");
    return 0;
}

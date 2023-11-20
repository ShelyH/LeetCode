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
            if (l_nums[i] != -1) {
                node->left = new TreeNode(l_nums[i]);
                que.push(node->left);
            }
            i++;
            if (i < l_nums.size() && l_nums[i] != -1) {
                node->right = new TreeNode(l_nums[i]);
                que.push(node->right);
            }
            i++;
        }
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        else if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> val = {3, 0, 4, -1, 2, -1, -1, 1};
    TreeNode* root = s.createTree(val);
    TreeNode* nroot = s.trimBST(root, 1, 3);
    system("pause");
    return 0;
}

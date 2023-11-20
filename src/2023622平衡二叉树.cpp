#include <iostream>
#include <queue>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    TreeNode* Create_Tree(vector<int>& l_nums)  // 层次遍历创建二叉树
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

    void levelOrder(TreeNode* root)
    {
        queue<TreeNode*> que;
        if (!root) {
            return;
        }

        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        cout << endl;
    }

    bool isBalanced(TreeNode* root)
    {
        int treeH = getTreeH(root);
        if (treeH == -1) {
            return false;
        }
        else {
            return true;
        }
    }

    int getTreeH(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }
        int leftH = getTreeH(node->left);
        if (leftH == -1) {
            return -1;
        }

        int rightH = getTreeH(node->right);
        if (rightH == -1) {
            return -1;
        }

        if (abs(leftH - rightH) > 1) {
            return -1;
        }
        else {
            return max(leftH, rightH) + 1;
        }
    }
};

int main()
{
    vector<int> level_nums = {3, 9, 20, NULL, NULL, 15, 7, 8};  // 层次数组
    Solution s;
    TreeNode* root = s.Create_Tree(level_nums);
    s.levelOrder(root);
    bool b = s.isBalanced(root);
    cout << b << endl;

    return 0;
}

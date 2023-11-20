
#include <iostream>
#include <queue>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    int diameter = 0;

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

    int diameterOfBinaryTree(TreeNode* root)
    {
        traversal(root);
        return diameter;
    }

    void traversal(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        diameter = left + right;
        traversal(root->left);
        traversal(root->right);
    }

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

int main()
{
    vector<int> val = {4, 1};
    Solution s;
    TreeNode* root = s.createTree(val);
    int di = s.diameterOfBinaryTree(root);
    system("pause");
    return 0;
}

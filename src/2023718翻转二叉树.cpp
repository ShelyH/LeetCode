
#include <iostream>
#include <queue>

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

    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main()
{
    vector<int> val = {4, 2, 7, 1, 3, 6, 9};
    Solution s;
    TreeNode* root = s.createTree(val);
    TreeNode* nroot = s.invertTree(root);
    system("pause");
    return 0;
}

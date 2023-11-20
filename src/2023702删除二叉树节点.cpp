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

    TreeNode* removeLeafNodes(TreeNode* root, int key)
    {
        if (root == NULL) {
            return NULL;
        }
        root->left = removeLeafNodes(root->left, key);
        root->right = removeLeafNodes(root->right, key);
        if (root->val == key && root->left == NULL && root->right == NULL) {
            return NULL;
        }
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> val = {1, 2, 3, 2, NULL, 2, 4};
    TreeNode* root = s.createTree(val);
    TreeNode* nroot = s.removeLeafNodes(root, 2);

    system("pause");
    return 0;
}

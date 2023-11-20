
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

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
    {
        if (root == nullptr || root->val == p || root->val == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        else if (left != nullptr && right == nullptr) {
            return left;
        }
        else if (left == nullptr && right != nullptr) {
            return right;
        }
        else {
            return nullptr;
        }
    }
};

int main()
{
    Solution s;
    vector<int> val = {3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4};
    TreeNode* root = s.createTree(val);
    TreeNode* node = s.lowestCommonAncestor(root, 7, 8);
    cout << node->val << endl;
    system("pause");
    return 0;
}


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

    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) {
            return false;
        }
        bool res = hasPath(root, targetSum - root->val);
        return res;
    }

    bool hasPath(TreeNode* node, int count)
    {
        if (node->left == nullptr && node->right == nullptr && count == 0) {
            return true;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return false;
        }
        if (node->left) {
            if (hasPath(node->left, count - node->left->val)) {
                return true;
            }
        }
        if (node->right) {
            if (hasPath(node->right, count - node->right->val)) {
                return true;
            }
        }
        return false;
    }
};

// int main()
//{
//	Solution s;
//	vector<int> val = { 5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1 };
//	TreeNode* root = s.Create_Tree(val);
//	bool res = s.hasPathSum(root, 11);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
// }

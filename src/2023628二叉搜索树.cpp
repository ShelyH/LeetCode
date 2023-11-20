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

    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr || root->val == val) {
            return root;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};

// int main()
//{
//	Solution s;
//	vector<int> val = { 4,2,7,1,3 };
//	TreeNode* root = s.createTree(val);
//	TreeNode* subroot = s.searchBST(root, 2);
//	system("pause");
//	return 0;
// }

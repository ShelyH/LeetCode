#include <iostream>
#include <queue>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    vector<int> res;

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

    void traversal(TreeNode* cur)
    {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        if (pre == nullptr) {
            count = 1;
        }
        else if (pre->val == cur->val) {
            count++;
        }
        else {
            count = 1;
        }
        pre = cur;
        if (count == maxCount) {
            res.push_back(cur->val);
        }
        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }
        traversal(cur->right);
        return;
    }

    vector<int> findMode(TreeNode* root)
    {
        if (root == nullptr) {
            return res;
        }
        traversal(root);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> val = {1, NULL, 2, 2, 2};
    TreeNode* root = s.createTree(val);
    vector<int> res = s.findMode(root);
    system("pause");
    return 0;
}

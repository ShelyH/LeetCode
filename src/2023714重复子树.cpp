#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
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

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        vector<TreeNode*> res;
        unordered_map<string, int> map;
        traversal(root, res, map);

        return res;
    }

    string traversal(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& map)
    {
        if (root == nullptr) {
            return "";
        }

        string left = traversal(root->left, res, map);
        string right = traversal(root->right, res, map);
        string subtree = to_string(root->val) + ',' + left + ',' + right;
        map[subtree]++;
        if (map[subtree] == 2) {
            res.push_back(root);
        }
        return subtree;
    }
};

int main()
{
    vector<int> val = {1, 2, 3, 4, NULL, 2, 4, NULL, NULL, 4};
    Solution s;
    TreeNode* root = s.createTree(val);
    vector<TreeNode*> res = s.findDuplicateSubtrees(root);

    system("pause");
    return 0;
}


#include <iostream>
#include <queue>
#include <string>
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

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<int> path;
        vector<string> result;
        if (!root) {
            return result;
        }
        getBinaryTreePaths(root, path, result);
        return result;
    }

    void getBinaryTreePaths(TreeNode* node, vector<int>& path, vector<string>& result)
    {
        path.push_back(node->val);
        // 判断终止
        if (!node->left && !node->right) {
            string pathstr;
            for (int i = 0; i < path.size() - 1; i++) {
                pathstr += to_string(path[i]);
                pathstr += "->";
            }
            pathstr += to_string(path[path.size() - 1]);
            result.push_back(pathstr);
            return;
        }

        if (node->left) {
            getBinaryTreePaths(node->left, path, result);  // 递归
            path.pop_back();                               // 回溯
        }
        if (node->right) {
            getBinaryTreePaths(node->right, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    vector<int> value = {1, 2, 3, NULL, 5, 7, NULL, NULL, 9, 10};
    Solution s;
    TreeNode* root = s.createTree(value);
    vector<string> res = s.binaryTreePaths(root);
    for (auto path : res) {
        cout << path << endl;
    }

    system("pause");
    return 0;
}

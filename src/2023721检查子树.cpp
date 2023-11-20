
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

    bool checkSubTree(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL || t2 == NULL) {
            return false;
        }
        bool res = dfs(t1, t2);
        bool left = checkSubTree(t1->left, t2);
        bool right = checkSubTree(t1->right, t2);
        return res || left || right;
    }

    bool dfs(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        else if (t1 == nullptr || t2 == nullptr || t1->val != t2->val) {
            return false;
        }

        bool left = dfs(t1->left, t2->left);
        bool right = dfs(t1->right, t2->right);
        return left && right;
    }
};

int main()
{
    Solution s;
    vector<int> vala = {1, 2, 3, 4};
    vector<int> valb = {1};

    TreeNode* root = s.createTree(vala);
    TreeNode* subroot = s.createTree(valb);
    bool res = s.checkSubTree(root, subroot);
    cout << res << endl;

    system("pause");
    return 0;
}

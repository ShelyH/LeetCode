
#include <climits>
#include <iostream>
#include <queue>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    int sum = INT_MIN;

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

    int maxPathSum(TreeNode* root)
    {
        getmaxPath(root);
        return sum;
    }

    int getmaxPath(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, getmaxPath(root->left));
        int right = max(0, getmaxPath(root->right));
        sum = max(sum, root->val + left + right);

        return max(left, right) + root->val;
    }
};

int main()
{
    vector<int> val = {1, 2, 3, -1, 1};
    Solution s;
    TreeNode* root = s.createTree(val);
    int res = s.maxPathSum(root);
    cout << res;
    system("pause");
    return 0;
}

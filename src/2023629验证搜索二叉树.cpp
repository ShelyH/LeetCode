
#include <iostream>
#include <queue>
#include <stack>
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

    // 迭代中序遍历
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                if (pre != NULL && pre->val >= cur->val) {
                    return false;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> val = {5, 1, 4, NULL, NULL, 3, 6};
    TreeNode* root = s.createTree(val);
    bool res = s.isValidBST(root);
    cout << res << endl;

    system("pause");
    return 0;
}

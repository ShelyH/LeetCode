
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

    bool res;
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        subt(A, B);

        return res;
    }

    void subt(TreeNode* A, TreeNode* B)
    {
        if (A != nullptr && A->val == B->val) {
            res = traversal(A, B);
            return;
        }
        if (A == nullptr) {
            return;
        }
        subt(A->left, B);
        subt(A->right, B);
    }

    bool traversal(TreeNode* A, TreeNode* B)
    {
        if (A != nullptr && B == nullptr || A == nullptr && B != nullptr) {
            return false;
        }
        else if (A == nullptr && B == nullptr) {
            return true;
        }
        else if (A->val != B->val) {
            return false;
        }
        bool left = traversal(A->left, B->left);
        bool right = traversal(A->right, B->right);
        res = left && right;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vala = {1, 2, 3, 4};
    vector<int> valb = {3};
    TreeNode* A = s.createTree(vala);
    TreeNode* B = s.createTree(valb);
    s.isSubStructure(A, B);

    system("pause");
    return 0;
}

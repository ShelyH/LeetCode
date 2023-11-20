
#include <iostream>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return root;
        }

        int inInorder;
        for (inInorder = 0; inInorder < inorder.size(); inInorder++) {
            if (inorder[inInorder] == preorder[0]) {
                break;
            }
        }

        vector<int> leftInOrder(inorder.begin(), inorder.begin() + inInorder);
        vector<int> rightInOrder(inorder.begin() + inInorder + 1, inorder.end());
        // preorder.resize(preorder.size() - 1);
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + leftInOrder.size() + 1);
        vector<int> rightPreOrder(preorder.begin() + leftInOrder.size() + 1, preorder.end());

        root->left = buildTree(leftPreOrder, leftInOrder);
        root->right = buildTree(rightPreOrder, rightInOrder);

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = s.buildTree(preorder, inorder);

    system("pause");
    return 0;
}

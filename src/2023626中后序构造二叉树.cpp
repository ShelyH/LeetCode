
#include <iostream>
#include <vector>

#include "../include/二叉树.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);

        if (postorder.size() == 1) {
            return root;
        }
        int inIndex;
        for (inIndex = 0; inIndex < inorder.size(); inIndex++) {
            if (inorder[inIndex] == postorder[postorder.size() - 1]) {
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inIndex);
        vector<int> rightInorder(inorder.begin() + inIndex + 1, inorder.end());
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = s.buildTree(inorder, postorder);

    system("pause");
    return 0;
}

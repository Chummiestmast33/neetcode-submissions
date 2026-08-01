/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return bst(root, LLONG_MIN, LLONG_MAX); }

    bool bst(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return bst(root->left, minVal, root->val) && bst(root->right, root->val, maxVal);
    }
};

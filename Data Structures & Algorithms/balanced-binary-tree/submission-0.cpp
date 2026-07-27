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
    bool isBalanced(TreeNode* root) { return helper(root) != -1; }

   private:
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int rigth = helper(root->right);
        if (rigth == -1) return -1;
        int left = helper(root->left);
        if (left == -1) return -1;
        if (abs(rigth - left) <= 1) {
            return max(rigth, left) + 1;
        }
        return -1;
    }
};

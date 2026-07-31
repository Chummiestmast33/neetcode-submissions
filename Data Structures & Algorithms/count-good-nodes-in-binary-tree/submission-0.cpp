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
    int goodNodes(TreeNode* root) { return dfs(root, INT_MIN); }

    int dfs(TreeNode* root, int maxValue) {
        if (root == nullptr) return 0;
        int currentMaxValue;
        if (root->val >= maxValue) {
            currentMaxValue = root->val;
            return dfs(root->left, currentMaxValue) + dfs(root->right, currentMaxValue) + 1;
        }
        currentMaxValue = maxValue;
        return dfs(root->left, currentMaxValue) + dfs(root->right, currentMaxValue);
    }
};

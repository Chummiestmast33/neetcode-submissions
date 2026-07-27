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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot)) return true;
        }
        bool isRightSubTree = isSubtree(root->right, subRoot);
        bool isLeftSubTree = isSubtree(root->left, subRoot);
        return isRightSubTree || isLeftSubTree;
    }

   private:
    // Metod to compare if the subroot exist in the node
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == subRoot) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        bool rightSameTree = isSameTree(root->right, subRoot->right);
        bool leftSameTree = isSameTree(root->left, subRoot->left);
        if (leftSameTree && rightSameTree)
            if (root->val == subRoot->val) return true;
        return false;
    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) {  // Especial case when both are nullptr
            return true;
        }
        if (p == nullptr || q == nullptr) {  // only one have a value
            return false;
        }
        bool leftIsSame = isSameTree(p->left, q->left);
        bool rightIsSame = isSameTree(p->right, q->right);
        if (leftIsSame && rightIsSame)
            if (p->val == q->val) return true;
        return false;
    }
};

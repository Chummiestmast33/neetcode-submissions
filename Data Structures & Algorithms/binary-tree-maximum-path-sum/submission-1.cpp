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
    int maxSum = INT_MIN;

   public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }

    int maxPath(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        cout << root->val << " : " << left << "," << right << endl;
        int nodeMaxValue = max({left + root->val, right + root->val, root->val});
        maxSum = max({left + right + root->val, nodeMaxValue, maxSum});
        return nodeMaxValue;
    }
};

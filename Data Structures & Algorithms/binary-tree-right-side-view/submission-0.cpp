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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        int count = q.size();
        vector<int> rightView;
        while (q.size()) {
            int lastElement;
            while (count--) {
                TreeNode* current = q.front();
                q.pop();
                lastElement = current->val;
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }
            rightView.push_back(lastElement);
            count = q.size();
        }
        return rightView;
    }
};

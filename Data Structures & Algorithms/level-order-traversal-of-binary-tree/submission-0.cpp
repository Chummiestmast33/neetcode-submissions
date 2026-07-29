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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)  // In case there is no nodes
            return {};
        vector<vector<int>> answer;
        int count = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            vector<int> nums;
            while (count--) {
                nums.push_back(q.front()->val);
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            answer.push_back(nums);
            count = q.size();
        }
        return answer;
    }
};

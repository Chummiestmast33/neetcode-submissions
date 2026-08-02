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
    int currentIndex = 0;

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1, indexMap);
    }
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd,
                    unordered_map<int, int>& indexMap) {
        if (currentIndex >= preorder.size()) return nullptr;
        int currentValue = preorder[currentIndex++];
        int index = indexMap[currentValue];
        if (inStart <= index && inEnd >= index) {
            TreeNode* node = new TreeNode(currentValue);
            if (inStart == inEnd) return node;
            if (index == inStart) {
                node->left = nullptr;
            } else {
                node->left = build(preorder, inStart, index - 1, indexMap);
            }
            if (index == inEnd) {
                node->right = nullptr;
            } else {
                node->right = build(preorder, index + 1, inEnd, indexMap);
            }
            return node;
        }
        return nullptr;
    }
};

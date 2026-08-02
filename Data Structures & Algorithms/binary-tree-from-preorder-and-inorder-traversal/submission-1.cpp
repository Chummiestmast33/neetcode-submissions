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
        return build(preorder, 0, preorder.size() - 1, indexMap);
    }

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd,
                    unordered_map<int, int>& indexMap) {
        if (inStart > inEnd || currentIndex >= preorder.size()) return nullptr;
        int currentValue = preorder[currentIndex++];
        int index = indexMap[currentValue];
        TreeNode* node = new TreeNode(currentValue);
        node->left = build(preorder, inStart, index - 1, indexMap);
        node->right = build(preorder, index + 1, inEnd, indexMap);
        return node;
    }
};

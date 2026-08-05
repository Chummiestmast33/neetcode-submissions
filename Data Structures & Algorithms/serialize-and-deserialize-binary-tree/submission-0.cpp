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

class Codec {
    string serializatedTree = "";
    vector<string> values;
    int currentIndex = 0;

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfsSerialization(root);
        return serializatedTree;
    }

    void dfsSerialization(TreeNode* root) {
        if (root == nullptr) {
            serializatedTree += "#,";
            return;
        }
        serializatedTree += to_string(root->val) + ",";
        dfsSerialization(root->left);
        dfsSerialization(root->right);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            values.push_back(token);
        }
        return dfsDeserialization();
    }

    /*
        1,2,#,#,3,4,#,#,5,#,# preorder
    */
    TreeNode* dfsDeserialization() {
        if(values[currentIndex] == "#"){
            ++currentIndex;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(values[currentIndex++]));
        node->left = dfsDeserialization();
        node->right = dfsDeserialization();
        return node;
    }
};

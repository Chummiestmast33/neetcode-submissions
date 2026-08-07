/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializatedTree = "";
        dfsSerialization(root, serializatedTree);
        return serializatedTree;
    }

    void dfsSerialization(TreeNode* root, string& serializatedTree) {
        if (root == nullptr) {
            serializatedTree += "#,";
            return;
        }
        serializatedTree += to_string(root->val) + ",";
        dfsSerialization(root->left, serializatedTree);
        dfsSerialization(root->right, serializatedTree);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values;
        int currentIndex = 0;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            values.push_back(token);
        }
        return dfsDeserialization(values, currentIndex);
    }

    TreeNode* dfsDeserialization(vector<string>& values, int& currentIndex) {
        if (values[currentIndex] == "#") {
            ++currentIndex;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(values[currentIndex++]));
        node->left = dfsDeserialization(values, currentIndex);
        node->right = dfsDeserialization(values, currentIndex);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
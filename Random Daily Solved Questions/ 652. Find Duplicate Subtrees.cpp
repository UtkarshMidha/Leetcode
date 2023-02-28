class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees;
        vector<TreeNode*> duplicates;

        traverse(root, subtrees, duplicates);

        return duplicates;
    }

private:
    string traverse(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
        if (!node) {
            return "#";
        }

        string subtree = to_string(node->val) + "," + traverse(node->left, subtrees, duplicates) + "," + traverse(node->right, subtrees, duplicates);

        if (subtrees.count(subtree)) {
            if (subtrees[subtree] == 1) {
                duplicates.push_back(node);
            }
            subtrees[subtree]++;
        } else {
            subtrees[subtree] = 1;
        }

        return subtree;
    }
};

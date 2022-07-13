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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
           if(!root->right)
               return root->left;
        else{
            TreeNode* n=root->right;
            while(n->left)
                n=n->left;
            swap(n->val,root->val);
            root->right=deleteNode(root->right,key);
            return root;
        }
        }
        else if(root->val>key)
            root->left= deleteNode(root->left,key);
        else
            
            root->right= deleteNode(root->right,key);
        return root;
    }
};

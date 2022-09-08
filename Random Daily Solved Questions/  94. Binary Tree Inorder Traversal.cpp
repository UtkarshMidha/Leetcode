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
    vector<int> inorderTraversal(TreeNode* root) {
// // Recurssion 
//         vector<int> nodes;
//         inorder(root, nodes);
//         return nodes;
        
// // Iteration 
//         vector<int> ans;
//         stack<TreeNode *> stk;
//         TreeNode *curr=root;
//         while(curr or !stk.empty()){
//             while(curr){
//                 stk.push(curr);
//                 curr=curr->left;
//             }
//             curr=stk.top();
//             stk.pop();
            
//             ans.push_back(curr->val);
//             curr=curr->right;
//         }
//         return ans;
    
// Morris Traversal TC:O(N) SC:O(1)
    vector<int> ans;
        while(root){
            if(root->left){
                TreeNode *last=root->left;
                while(last->right and last->right!=root)
                    last=last->right;
            
            if(last->right==NULL){
                last->right=root;
                root=root->left;
                
            }
            else if(last->right==root){
                last->right=NULL;
                ans.push_back(root->val);
                root=root->right;
            }
                
            }
            else{
                {
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
            
        }
        return ans;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};

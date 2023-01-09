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
    vector<int> preorderTraversal(TreeNode* root) {
// // O(N) O(N)
//     vector<int> ans;
//     stack<TreeNode*> stk;
//         while(root or !stk.empty()){
//             if(root){
//                 ans.push_back(root->val);
//                 if(root->right)
//                     stk.push(root->right);
//                 root=root->left;
//             }
//             else{
//                 root=stk.top();
//                 stk.pop();
//             }
//         }
//         return ans;

    // Morris Traversal TC:O(N) SC:O(1)
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode *last=root->left;
                while(last->right and last->right!=root )
                    last=last->right;
                
                if(!last->right){
                    last->right=root;
                    ans.push_back(root->val);
                    root=root->left;
                    }
                
                else{
                    last->right=NULL;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    
    }
};

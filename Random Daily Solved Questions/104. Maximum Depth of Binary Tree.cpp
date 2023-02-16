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
//     int maxDepth(TreeNode* root) {
//         if(!root) return  0;
//         return solver(root,1);
//     }
//     int solver(TreeNode *root,int depth){
        
//         if(!root) return depth-1;
//         return max(solver(root->left,depth+1),solver(root->right,depth+1));
//         return depth; 
//     }
    //----------------------------------------------------------------------------------
    
// int maxDepth(TreeNode* root) {
//   return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;  
// }
    
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        int ans = 0, count = 0;
        TreeNode *cur;
        q.push(root);
        while (!q.empty())
        {
            ans++, count = q.size();
            while (count--)
            {
                cur = q.front();
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
        }
        return ans;
    }
};

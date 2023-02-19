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
// // Method 1 : BFS AND REVERSE AT END 
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int size=q.size();
//             vector<int> temp;
//             for(int i=0;i<size;i++){
//                 TreeNode *node=q.front();
//                 q.pop();
//                 temp.push_back(node->val);
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
                
//             }
//             ans.push_back(temp);
//         }
        
//         // reverse even index
//         for(int i=0;i<ans.size();i++){
//             if(i%2)
//                 reverse(ans[i].begin(),ans[i].end());
//         }
//         return ans;
//     }

// Method 2: BFS + BOOL variable for keeping track
 vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
};

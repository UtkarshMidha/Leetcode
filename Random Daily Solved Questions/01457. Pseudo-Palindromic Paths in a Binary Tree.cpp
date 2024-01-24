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
    
    bool isPalindrome(unordered_map<int, int>& mp) {
        
        int odd = 0;
        
        for(auto it: mp) {
            
            if(it.second % 2 != 0) {
                odd++;
            }
            if(odd > 1) {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(TreeNode* root, int& ans,  unordered_map<int, int>& mp) {
        
        if(root == NULL) {
            return;
        }
        
        mp[root->val]++;
        
        if(root->left == NULL && root->right == NULL) {
            
            if(isPalindrome(mp)) {
                ans++;
            }
            return;
        }
        
        if(root->left) {
            
            solve(root->left, ans, mp);
            mp[root->left->val]--;
        }
        
        if(root->right) {
            
            solve(root->right, ans, mp);
            mp[root->right->val]--;
        }
        
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        solve(root, ans, mp);
        
        return ans;
    }
};
// class Solution {
// public:
//     void rec(TreeNode* root) {
//         if (!root)
//             return;
        
//         m[root->val]++;
        
//         // If we got to a leaf - check if the path can be a polindrome
//         if (!root->left && !root->right) {
//             int odd = 0;
//             for (auto a : m)
//                 if (a.second % 2 == 1)
//                     odd++;

//             if (odd <= 1)
//                 res++;
//         }
        
//         rec(root->left);
//         rec(root->right);
//         m[root->val]--;
//     }
    
//     int pseudoPalindromicPaths (TreeNode* root) {
//         rec(root);
//         return res;
//     }
    
// private:
//     int res = 0;
//     unordered_map<int, int> m;
// };

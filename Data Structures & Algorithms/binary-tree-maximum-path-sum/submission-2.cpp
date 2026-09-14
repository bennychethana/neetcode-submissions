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
    int ans = INT_MIN;
    int f(TreeNode* root){ // max path sum ending at root
        if(!root) return 0;
        int l = f(root->left);
        int r = f(root->right);
        ans = max({ans,l+root->val,root->val+r,root->val,l+root->val+r});
        return max({l+root->val,root->val+r,root->val});
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};







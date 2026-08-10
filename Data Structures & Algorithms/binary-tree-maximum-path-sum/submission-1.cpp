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
    int f(TreeNode* root){ // max sum ending at root from below
        if(!root) return -1001;
        int l = f(root->left);
        int r = f(root->right);
        int mid = root->val;
        ans = max({ans,l,r,l+mid,mid+r,l+mid+r,mid});
        return max({l+mid,mid+r,mid});
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};

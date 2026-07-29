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
    bool ans = true;
    TreeNode* prev = nullptr;
    void f(TreeNode* root){
        if(!root || !ans) return;
        f(root->left);
        if(prev && root->val<=prev->val){
            ans = false;
            return;
        }
        prev = root;
        f(root->right);
    }
    bool isValidBST(TreeNode* root) {
        // TreeNode* prev = nullptr;
        f(root);
        return ans;
    }
};

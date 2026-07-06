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
    static bool comparator(TreeNode* node1,TreeNode* node2){
        return node1->val<node2->val;
    }
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    vector<TreeNode*> v;
    void f(TreeNode* root){
        if(!root) return;
        f(root->left);
        v.push_back(root);
        f(root->right);
    }
    void recoverTree(TreeNode* root) {
        f(root);
        int n = v.size();
        vector<TreeNode*> v2 = v;
        sort(v2.begin(),v2.end(),comparator);
        for(int i=0;i<n;i++){
            if(v[i]!=v2[i]){
                node1 = v[i];
                node2 = v2[i];
                break;
            }
        }
        int t = node1->val;
        node1->val = node2->val;
        node2->val = t;
    } 
};
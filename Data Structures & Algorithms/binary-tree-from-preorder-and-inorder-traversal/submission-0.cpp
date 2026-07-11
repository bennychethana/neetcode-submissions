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
    unordered_map<int,int> map;
    int n = 0;
    int preorder_index = 0;
    TreeNode* f(vector<int>& preorder,int start,int end){
        if(start>end) return nullptr;
        int cur_val = preorder[preorder_index];
        TreeNode* cur_root = new TreeNode(cur_val);
        int inorder_index = map[cur_val];
        preorder_index++;
        cur_root->left = f(preorder,start,inorder_index-1);
        cur_root->right = f(preorder,inorder_index+1,end);
        return cur_root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        n = preorder.size();
        return f(preorder,0,n-1);
    }
};

// get cur_root from preorder
// get left & right subtree from inorder

// 1
// p: 1 2 3 4
// i: 2 1 3 4

// f(2 1 3 4)
// f(2) f(3 4)


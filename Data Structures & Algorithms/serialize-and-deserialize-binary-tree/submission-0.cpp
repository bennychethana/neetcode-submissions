/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        if(!root) return "N_";
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            for(int i=0;i<l;i++){
                TreeNode* f = q.front();
                q.pop();
                if(f){
                    s+=to_string(f->val)+'_';
                    q.push(f->left);
                    q.push(f->right);
                }
                else{
                    s+="N_";
                }
            }
        }
        return s; // 1-2-3-N-N-4-5-
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="" || data=="N_") return nullptr;
        queue<TreeNode*> q;
        stringstream ss(data);
        string token;
        getline(ss,token,'_');
        TreeNode* root = new TreeNode(stoi(token));
        q.push(root);
        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();
            getline(ss,token,'_'); // left child
            if(token!="N"){
                TreeNode* left_child = new TreeNode(stoi(token));
                parent->left = left_child;
                q.push(left_child);
            }
            getline(ss,token,'_'); // right child
            if(token!="N"){
                TreeNode* right_child = new TreeNode(stoi(token));
                parent->right = right_child;
                q.push(right_child);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
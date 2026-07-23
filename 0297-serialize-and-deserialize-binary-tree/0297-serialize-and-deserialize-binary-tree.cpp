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
        string st="";
        queue<TreeNode*> q;
        if (!root) return "";
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL){
                st.append("#,");
            }
            else
            st.append(to_string(cur->val)+",");
            if(cur!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        queue<TreeNode*> q;
        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode* node =new TreeNode(stoi(str));
        q.push(node);
        
        while(!q.empty()){
            TreeNode* node1= q.front();
            q.pop();
            getline(s,str,',');

            if(str =="#"){
                node1->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                node1->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');

            if(str =="#"){
                node1->right=NULL;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                node1->right=rightnode;
                q.push(rightnode);
            }





        }
        return node;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
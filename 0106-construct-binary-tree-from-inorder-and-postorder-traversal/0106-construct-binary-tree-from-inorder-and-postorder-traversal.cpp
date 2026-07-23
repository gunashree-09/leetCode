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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(postorder, 0, postorder.size()-1,
                     inorder, 0, inorder.size()-1, mp);
    }

    TreeNode* build(vector<int>& postorder,
                    int postst,
                    int postend,
                    vector<int>& inorder,
                    int inst,
                    int inend,
                    unordered_map<int,int>& mp){

        if(postst > postend || inst > inend)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = mp[root->val];
        int leftSize = inroot - inst;

        root->left = build(postorder,
                           postst,
                           postst + leftSize - 1,
                           inorder,
                           inst,
                           inroot - 1,
                           mp);

        root->right = build(postorder,
                            postst + leftSize,
                            postend - 1,
                            inorder,
                            inroot + 1,
                            inend,
                            mp);

        return root;
    }
};
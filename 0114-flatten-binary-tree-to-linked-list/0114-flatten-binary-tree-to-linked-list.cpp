class Solution {
public:
    void preorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return ;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    void flatten(TreeNode* root) {
        if(root==NULL )return;
        vector<int>v;
        preorder(root,v);
        TreeNode* temp = root;

        for (int i = 1; i < v.size(); i++) {
            TreeNode* t = new TreeNode(v[i]);

            temp->left = NULL;
            temp->right = t;

            temp = t;
        }
    }
};
class Solution {
public:
    void preorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return ;
        preorder(root->left,v);
        v.push_back(root->val);
        preorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        preorder(root,v);
        return v[k-1];
    }
};
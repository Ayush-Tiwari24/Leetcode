class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* construct(int lo,int hi,vector<int>& v){
        if(lo>hi)return NULL;
        int mid=hi+(lo-hi)/2;
        TreeNode* nr=new TreeNode(v[mid]);
        nr->left=construct(lo,mid-1,v);
        nr->right=construct(mid+1,hi,v);
        return nr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int lo=0,hi=v.size()-1;
        return construct(lo,hi,v);
    }
};
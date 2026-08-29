class Solution {
public:
    int currsum=0;
    void inorder(TreeNode* root,int& sum){
        if(root==NULL)return;
        inorder(root->left,sum);
        sum+=root->val;
        inorder(root->right,sum);
    }
    void gst(TreeNode* root,int sum){
        if(root==NULL)return ;
        gst(root->left,sum);
        currsum+=root->val;
        root->val+=sum-currsum;
        gst(root->right,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        inorder(root,sum);
        gst(root,sum);
        return root;
    }
};
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    long long lOrder(TreeNode* root,int level) {
        if(root==NULL)return LLONG_MIN;
        if(level==0)return root->val;
        long long left=lOrder(root->left,level-1);
        if(left!=LLONG_MIN)return left;
        return lOrder(root->right,level-1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int n = level(root);
        return lOrder(root,n-1);
    }
};
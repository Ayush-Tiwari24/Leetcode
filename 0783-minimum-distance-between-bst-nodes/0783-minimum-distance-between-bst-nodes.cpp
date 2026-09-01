class Solution {
public:
    void mindiff(TreeNode* root,TreeNode*& prev,int& mini){
        if(root==NULL)return;
        mindiff(root->left, prev, mini);

        if (prev != NULL) {
            mini = min(mini, root->val - prev->val);
        }

        prev = root;

        mindiff(root->right, prev, mini);
    }
    int minDiffInBST(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=NULL;
        mindiff(root,prev,mini);
        return mini;
    }
};
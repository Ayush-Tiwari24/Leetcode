class Solution {
public:
    int lefth(TreeNode* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }
    int righth(TreeNode* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        if(righth(root)==lefth(root))return pow(2,righth(root))-1;
        return 1+countNodes(root->left)+ countNodes(root->right);
    }
};
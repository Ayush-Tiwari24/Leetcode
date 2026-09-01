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
    void mindiff(TreeNode* root,TreeNode*& prev,int& mini){
        if(root==NULL)return;
        mindiff(root->left, prev, mini);

        if (prev != NULL) {
            mini = min(mini, root->val - prev->val);
        }

        prev = root;

        mindiff(root->right, prev, mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=NULL;
        mindiff(root,prev,mini);
        return mini;
    }
};
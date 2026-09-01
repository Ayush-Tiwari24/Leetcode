/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void path(TreeNode* root, string s, vector<string>& v) {
        if (root == NULL)
            return;

        s += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            v.push_back(s);
            return;
        }
        path(root->left, s, v);
        path(root->right, s, v);
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        vector<string> v;
        path(root, s, v);
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += stoi(v[i]);
        }
        return ans;
    }
};
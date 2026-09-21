class Solution {
public:
    unordered_map<int,int> m;

    int sum(TreeNode* root){
        if(root==NULL) return 0;

        int s = root->val + sum(root->left) + sum(root->right);
        m[s]++;

        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        sum(root);
        int maxi=0;
        for(auto ele:m){
            maxi=max(maxi,ele.second);
        }
        for(auto ele:m){
            if(ele.second==maxi){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};
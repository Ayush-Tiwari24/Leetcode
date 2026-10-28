class Solution {
public:
    unordered_map<int,vector<int>>m;
    vector<int>v;
    Solution(vector<int>& nums) {
        v=nums;
        for(int i=0;i<v.size();i++){
            m[v[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        
        return m[target][rand()%m[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
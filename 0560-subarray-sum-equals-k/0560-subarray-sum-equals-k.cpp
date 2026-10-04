class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        } 

        int count = 0;
        unordered_map<int,int>m;
        for(auto x : prefix) {
            if(m.find(x-k) != m.end())
                count += m[x-k];

            m[x]++;
        }

        return count;
    }
};
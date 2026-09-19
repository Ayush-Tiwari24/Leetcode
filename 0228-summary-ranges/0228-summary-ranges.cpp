class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0){
            return ans;
        }
        if(nums.size()==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int first= nums[0];
        for(int i=0;i<nums.size();i++){
            if(i + 1 < nums.size() && nums[i+1]==nums[i]+1)continue;
            if(nums[i]!=first)ans.push_back(to_string(first)+"->"+to_string(nums[i]));
            else ans.push_back(to_string(nums[i]));
            if(i + 1 < nums.size())first=nums[i+1];
        }
        return ans;
    }
};
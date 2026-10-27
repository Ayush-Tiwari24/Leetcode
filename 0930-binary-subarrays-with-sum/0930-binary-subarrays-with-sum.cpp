class Solution {
public:
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.find(sum-goal)!=m.end())count+=m[sum-goal];
            if(sum==goal)count++;
            m[sum]++;
        }
        return count;
    }
};
class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int,int>m;
        int i=0,j=0;
        int count=0;
        while(j<nums.size()){
            m[nums[j]]++;
            
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};
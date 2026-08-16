class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prev=nums[0];
        int count=1;
        int ans;
        if(nums.size()==1)return nums[0];

        for(int i=1;i<nums.size();i++){
            if(prev==nums[i]){
                count++;
            }
            else {
                count--;
            }
            if(count==0){
                prev=nums[i];
                count=1;
            }
        }
        return prev;
    }
};
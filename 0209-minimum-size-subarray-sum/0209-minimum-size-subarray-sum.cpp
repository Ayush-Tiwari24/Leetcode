class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int i=0,j=0;
        int minil=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                minil=min(minil,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(j-i==nums.size())return 0;
        return minil;
    }
};
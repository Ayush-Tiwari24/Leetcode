class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIdx=0;
        int count=0;
        int currentMax=0;
        if(nums.size()<=1)return 0;
        for(int i=0;i<nums.size();i++){
            maxIdx=max(maxIdx,i+nums[i]);
            if(i==currentMax){
                count++;
                currentMax=maxIdx;
            }
            if(currentMax>=nums.size()-1)break;
        } 
        return count;
    }
};
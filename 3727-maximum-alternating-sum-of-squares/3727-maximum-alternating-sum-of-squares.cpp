class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        priority_queue<int>maxh;
        priority_queue<int,vector<int>,greater<int>>minh;

        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
            minh.push(nums[i]);
            maxh.push(nums[i]);

        }
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                sum+=maxh.top();
                maxh.pop();
            }else{
                sum-=minh.top();
                minh.pop();
            }
        }
        return sum;
    }
};
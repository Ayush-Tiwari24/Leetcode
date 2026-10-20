class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        while(k>0){
            int ele=pq.top();
            if(ele==0)break;
            else {
                pq.pop();
                pq.push(-1*ele);
                sum=sum-ele+(-1*ele);
            }
            k--;
        }
        return sum;
    }
};
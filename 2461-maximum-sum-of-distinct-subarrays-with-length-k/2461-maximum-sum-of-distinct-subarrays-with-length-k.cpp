class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        long long maxx=0,sum=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(j-i<k){
                if(m[nums[j]]<1){
                    m[nums[j]]++;
                    sum+=nums[j];
                    j++;
                    if(j-i==k){
                        maxx=max(sum,maxx);
                        sum-=nums[i];
                        m[nums[i]]--;
                        i++;
                    }
                }
                else{
                    sum -= nums[i];
                    m[nums[i]]--;
                    i++;
                }

            }
        }
        return maxx;
    }
};
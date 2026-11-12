class Solution {
public:
    // int f(vector<int>&v,int idx,vector<int>&dp){
    //     if(idx>v.size()-1)return 0;
    //     if(idx==v.size()-1)return v[idx];
    //     if(idx==v.size()-2)return max(v[idx],v[idx+1]);

    //     if(dp[idx]!=-1)return dp[idx];
    //     dp[idx]=max(v[idx]+f(v,idx+2,dp),0+f(v,idx+1,dp));
    //     return dp[idx];
    // }
    int fbu(vector<int>&v,vector<int>&dp){
        int n=v.size();

        if(n==1)return v[0];

        dp[n-1]=v[n-1];
        dp[n-2]=max(v[n-1],v[n-2]);
        for(int i=v.size()-3;i>=0;i--){
            dp[i]=max(dp[i+1],dp[i+2]+v[i]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        return fbu(nums,dp);
    }
};
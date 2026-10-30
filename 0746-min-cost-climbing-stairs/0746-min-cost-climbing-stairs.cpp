class Solution {
public:
    int mini(vector<int>& cost,int i,vector<int>& dp){
        if(i<0)return 0;
        if(i==0)return cost[0];
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i]+min(mini(cost,i-1,dp),mini(cost,i-2,dp)) ;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0;
        int n=cost.size();
        vector<int>dp(cost.size(),-1);
        return min(mini(cost,n-1,dp),mini(cost,n-2,dp));
    }
};
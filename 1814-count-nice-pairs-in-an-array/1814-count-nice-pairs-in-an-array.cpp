class Solution {
public:
    int rev(int a) {
        int ans=0;
        while (a > 0) {
            int digit = a % 10;
            ans = ans * 10 + digit;
            a /= 10;
        }
        return ans;
    }
    int fact(int n){
        if(n<=1)return 1;
        return n*fact(n-1);
    }
    int combi(int n,int r){
        return fact(n) / (fact(r) * fact(n-r));
    }
    int countNicePairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        unordered_map<int,int>m;
        for(auto x:nums){
            if(m.find(x)!=m.end()){
                count=count%1000000007;
                count+=m[x];
            }
            m[x]++;
        }
        return count%1000000007;
    }
};
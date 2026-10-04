class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        vector<int>pre(n+1,0);
        unordered_map<int,int>m;
        m[pre[0]]++;
        for(int i=1;i<pre.size();i++){
            if(nums[i-1]%2!=0)pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
            m[pre[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m.find(pre[i]+k)!=m.end())count+=m[pre[i]+k];
        }
        return count;
    }
};
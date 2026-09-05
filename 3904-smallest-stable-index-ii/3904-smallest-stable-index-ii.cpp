class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi;
        vector<int>mini;
        int maxele=INT_MIN;
        int minele=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxele=max(maxele,nums[i]);
            maxi.push_back(maxele);
        }
        for(int i=nums.size()-1;i>=0;i--){
            minele=min(minele,nums[i]);
            mini.push_back(minele);
        }
        reverse(mini.begin(),mini.end());
        int ans=INT_MAX;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi[i]-mini[i]<ans && maxi[i]-mini[i]<=k){
                ans=maxi[i]-mini[i];
                ind=i;
                break;
            }
        }
        return ind;
    }
};
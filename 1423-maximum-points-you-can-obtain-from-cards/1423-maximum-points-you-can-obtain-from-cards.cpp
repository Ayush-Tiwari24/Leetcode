class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=cardPoints[i];
        }
        int ans=0;
        for(int i=0;i<n-k;i++){
            ans+=cardPoints[i];
        }
        int j=n-k;
        int t=n-k;
        int mini=ans;
        for(int i=1;i<n-t+1;i++){
            ans+=cardPoints[j]-cardPoints[i-1];
            mini=min(mini,ans);
            j++;
        }
        
        return total-mini;
    }
};
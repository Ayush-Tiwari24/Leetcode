class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end());
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < current[1]) {
                ans++;
                current[1]=min(current[1],intervals[i][1]);
            } else {
                current = intervals[i];
            }
        }
        return ans;
    }
};
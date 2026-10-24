class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(intervals[mid][0]>newInterval[0]){
                r=mid;
            }
            else {
                l=mid+1;
            }
        }
        intervals.insert(intervals.begin() + l, newInterval);
        n=intervals.size();
        vector<int>current=intervals[0];
        // ans.push_back(current);
        for(int i=0;i<n;i++){
            if(current[1]>=intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            }else {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};
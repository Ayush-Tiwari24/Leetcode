class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        vector<int> current = points[0];
        for (int i = 1; i < points.size(); i++) {
            if(points[i][0] <= current[1]) {
                ans++;
                current[1]=min(current[1],points[i][1]);
            } else {
                current = points[i];
            }
        }
        return points.size()-ans;
    }
};
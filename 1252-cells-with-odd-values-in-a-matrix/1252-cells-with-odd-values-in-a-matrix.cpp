class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> v(m, vector<int> (n,0));
        int num = 0,r,c; 
        for(int i = 0; i < indices.size(); i++){
            r = indices[i][0];
            c = indices[i][1];
            for(int j = 0; j < v[0].size(); j++){
                v[r][j] += 1;
            }
            for(int j = 0; j < v.size(); j++){
                v[j][c] += 1;
            }
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] % 2 != 0) num++;
            }
        }
        return num;
    }
};
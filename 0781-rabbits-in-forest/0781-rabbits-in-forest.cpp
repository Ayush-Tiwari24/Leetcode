class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans=0;
        for(int x:answers){
            if(m.find(x)==m.end())ans+=x+1;
            m[x]++;
            if(m[x]==x+1){
                m.erase(x);
            }
        }
        
        return ans;
    }
};
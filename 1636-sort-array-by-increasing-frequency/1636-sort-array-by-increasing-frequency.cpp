class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >pq;
        for(int x:nums){
            m[x]++;
        }
        vector<int>ans;
        for(auto x:m){
            pq.push({x.second,-x.first});
        }
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++)ans.push_back(-pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >pq;
        for(int x:nums){
            m[x]++;
        }
        vector<int>ans;
        for(auto x:m){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
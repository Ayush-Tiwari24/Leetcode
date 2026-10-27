class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(auto x:m){
            int n=x.second;
            char c=x.first;
            pq.push({n,c});
        }
        s="";
        while(pq.size()!=0){
            for(int i=0;i<pq.top().first;i++){
                s+=pq.top().second;
            }
            pq.pop();
        }
        return s;
    }
};

class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string> a, pair<int,string> b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> m;

        for(string x : words) {
            m[x]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        for(auto x : m) {
            pq.push({x.second, x.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end(), [&](string a, string b) {
            if(m[a] == m[b]) return a < b;
            return m[a] > m[b];
        });

        return ans;
    }
};

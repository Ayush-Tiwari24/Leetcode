class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,pair<int,int>>>pq;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                if(pq.size()>k)pq.pop();
            }
        }
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        return {x,y};
    }
};
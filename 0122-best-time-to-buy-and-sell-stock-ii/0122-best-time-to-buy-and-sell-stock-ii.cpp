class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>s;
        s.push(prices[0]);
        int total=0;
        int ans=0;
        int mini=s.top();
        for(int i=1;i<prices.size();i++){
            while(!s.empty() && s.top()>prices[i]){
                s.pop();
                total+=ans;
                mini=prices[i];
                s.push(prices[i]);
            }
            if(prices[i]>=s.top()){
                ans=prices[i]-mini;
                if(i==prices.size()-1){
                    total+=ans;
                }
                s.push(prices[i]);
            }
        }
        return total;
    }
};
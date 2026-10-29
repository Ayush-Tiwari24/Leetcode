class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int total=0,start=prices[0];
        for(int i=1;i<prices.size();i++){
            if (prices[i]<start) {
                start = prices[i];
            } 
            else if(prices[i]-start>fee){
                total+=prices[i]-start-fee;
                start=prices[i]-fee;
            }
        }
        return total;
    }
};
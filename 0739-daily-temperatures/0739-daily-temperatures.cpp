class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>v(n,0);
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && temperatures[st.top()]<=temperatures[i])st.pop();
             if(st.size()>0)v[i]=st.top();
             else v[i]=i;
             st.push(i);
        }
        for(int i=0;i<temperatures.size();i++){
            v[i]-=i;
        }
        return v;
    }
};
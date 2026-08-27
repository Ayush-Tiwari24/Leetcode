class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        while(i == pushed.size() && i<pushed.size() || j<popped.size()){
            if(i==pushed.size() && st.top()!=popped[j])return false;
            if(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            else if(pushed[i]!=popped[j]){
                st.push(pushed[i]);
                i++;
            }
            else if(pushed[i]==popped[j]){
                st.push(pushed[i]);
                i++;
                st.pop();
                j++;
            }
        }
        return true;
    }
};
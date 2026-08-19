class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='*')st.pop();
            else st.push(s[i]);
            i++;
        }
        int x=st.size();
        s="";
        for(int i=0;i<x;i++){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
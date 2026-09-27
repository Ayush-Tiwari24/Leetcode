class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string n="";
        for(int i=0;i<s.size();i++){
            n="";
            if(s[i]==')'){
                while(st.top()!='('){
                    n.push_back(st.top());
                    st.pop();
                }
                st.pop();
                    for(int j=0;j<n.size();j++){
                        st.push(n[j]);
                    }
            }
            else st.push(s[i]);
        }
        string ans="";
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
            if(st.size()==0)reverse(ans.begin(),ans.end());
        }

        return ans;
    }
};
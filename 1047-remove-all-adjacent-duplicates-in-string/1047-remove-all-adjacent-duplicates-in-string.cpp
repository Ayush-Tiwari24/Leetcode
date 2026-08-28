class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            bool flag=false;
            while(!st.empty() && s[i]==st.top()){
                flag=true;
                st.pop();
            }
            if(st.empty() && flag==false)st.push(s[i]);
            else if(flag==false)st.push(s[i]);
        }
        string r="";
        while(!st.empty()){
            r+=st.top();
            st.pop();
        }
        reverse(r.begin(),r.end());
        return r;
    }
};
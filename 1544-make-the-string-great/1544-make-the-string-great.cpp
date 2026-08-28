class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(char c : s) {
            if(!st.empty() && tolower(st.top()) == tolower(c) && st.top() != c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string r = "";

        while(!st.empty()) {
            r += st.top();
            st.pop();
        }

        reverse(r.begin(), r.end());

        return r;
    }
};
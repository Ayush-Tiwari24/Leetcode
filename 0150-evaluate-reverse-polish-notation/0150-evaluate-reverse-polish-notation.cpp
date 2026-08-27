class Solution {
public:
    void calculateTop(stack<int>& st1,string op) {
        int p = st1.top();
        st1.pop();

        int q = st1.top();
        st1.pop();

        if (op == "+")
            st1.push(q + p);
        else if (op == "-")
            st1.push(q - p);
        else if (op == "*")
            st1.push(q * p);
        else if (op == "/")
            st1.push(q / p);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
        
            if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/")calculateTop(st,tokens[i]);
            else st.push(stoi(tokens[i]));
        }
            return st.top();
    }
};
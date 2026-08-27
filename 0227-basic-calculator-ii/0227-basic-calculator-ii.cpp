class Solution {
public:

    int priority(char op) {
        if (op == '+' || op == '-')
            return 1;

        if (op == '*' || op == '/')
            return 2;

        return 0;
    }

    void calculateTop(stack<int>& st1, stack<char>& st2) {
        char op = st2.top();
        st2.pop();

        int p = st1.top();
        st1.pop();

        int q = st1.top();
        st1.pop();

        if (op == '+')
            st1.push(q + p);
        else if (op == '-')
            st1.push(q - p);
        else if (op == '*')
            st1.push(q * p);
        else if (op == '/')
            st1.push(q / p);
    }

    int calculate(string s) {
        stack<int> st1;
        stack<char> st2;

        int i = 0;

        while (i < s.length()) {

            if (s[i] == ' ') {
                i++;
                continue;
            }

            if (isdigit(s[i])) {
                int num = 0;

                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                st1.push(num);
            }
            else {
                while (!st2.empty() &&
                       priority(st2.top()) >= priority(s[i])) {

                    calculateTop(st1, st2);
                }

                st2.push(s[i]);
                i++;
            }
        }

        while (!st2.empty()) {
            calculateTop(st1, st2);
        }

        return st1.top();
    }
};
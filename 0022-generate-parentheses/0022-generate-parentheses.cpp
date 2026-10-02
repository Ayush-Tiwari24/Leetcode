class Solution {
public:
    void gp(string s, int open, int close, vector<string>& para) {
        if (open== 0 && close == 0) {
            para.push_back(s);
            return;
        }
            if (open!=0) {
                gp(s + '(', open - 1, close, para);
            }
            if (open< close)
                gp(s + ')', open, close - 1, para);
        }
    vector<string> generateParenthesis(int n) {
        vector<string> para;

        gp("", n, n, para);
        return para;
    }

}
;
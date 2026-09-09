class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>m1;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch =t[i];
            if(m1.find(ch)!=m1.end()){
                m1[ch]--;
                if(m1[ch]==0)m1.erase(ch);
            }
            else return false;
        }
        return true;
    }
};
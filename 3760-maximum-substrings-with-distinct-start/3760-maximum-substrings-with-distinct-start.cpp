class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int>m;
        int longest=0;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]<1)m[s[i]]++;
        }
        return m.size();
    }
};
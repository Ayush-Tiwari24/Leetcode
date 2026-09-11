class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int l=0,r=0;
        int maxi=0;
        while(r<s.length()){
            if( (m[s[r]]<1)){
                m[s[r]]++;
                r++;
            }
            else{
                m[s[l]]--;
                l++; 
                // m[s[r]]--;
            }
            maxi=max(maxi,r-l);
        }
        return maxi;
    }
};
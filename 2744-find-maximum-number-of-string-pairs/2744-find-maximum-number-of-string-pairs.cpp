class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>st;
        int count=0;
        for(int i=0;i<words.size();i++){
            st.insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(words[i]==rev)continue;
            if(st.find(rev)!=st.end()){
                count++;
                st.erase(words[i]);
            }
        }
        return count;
    }
};
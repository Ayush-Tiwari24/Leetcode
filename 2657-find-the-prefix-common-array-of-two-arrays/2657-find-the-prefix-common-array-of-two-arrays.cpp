class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        vector<int>ans;
        int count=0;
        for(int i=0;i<a.size();i++){
            m1[a[i]]++;
            m2[b[i]]++;
            if(m1.find(b[i])!=m1.end())count++;
            if(m2.find(a[i])!=m2.end() && a[i]!=b[i])count++;
            ans.push_back(count);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int>s2;
        unordered_set<int>s1;
        for(int ele:nums1)s1.insert(ele);
        for(int ele:nums2)s2.insert(ele);
        for(int ele :s1){
            if(s2.find(ele)!=s2.end())ans.push_back(ele);
        }
        return ans;
        
    }
};
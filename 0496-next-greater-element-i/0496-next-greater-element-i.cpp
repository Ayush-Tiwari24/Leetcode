class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        vector<int>v(n);
        st.push(nums2[n-1]);
        v[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top()<=nums2[i])st.pop();
            if(st.empty())v[i]=-1;
            else v[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    ans[i] = v[j];
                    break;
                }
            }
        }
        return ans;
    }
};
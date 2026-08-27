class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>v(n);
        st.push(nums[n-1]);
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            while(st.size()>0 && st.top()<=nums[ind])st.pop();
            if(st.empty())v[ind]=-1;
            else v[ind] = st.top();
            st.push(nums[ind]);
        }
        return v;
    }
};
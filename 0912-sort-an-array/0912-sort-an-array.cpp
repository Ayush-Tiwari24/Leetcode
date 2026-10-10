class Solution {
public:
    vector<int> sort(vector<int>& nums,int l,int r,vector<int>ans){
        if (l >= r) {
            vector<int> temp;
            if (l == r) temp.push_back(nums[l]);
            return temp;
        }
        int mid=l+(r-l)/2;
        vector<int>v1;
        vector<int>v2;
        v1=sort(nums,l,mid,ans);
        v2=sort(nums,mid+1,r,ans);
        merge(v1,v2,ans);
        return ans;
    }
    void merge(vector<int>& v1,vector<int>& v2,vector<int>& ans){
        int i=0,j=0;
        while(i<v1.size()&& j<v2.size()){
            if(v1[i]<v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans;
        int l=0,r=nums.size()-1;
        return sort(nums,l,r,ans);
    }
};
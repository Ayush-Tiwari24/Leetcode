class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]<10)nums.push_back(nums[i]);
            
            else {
                string str=to_string(nums[i]);
                reverse(str.begin(),str.end());
                int n=stoi(str);
                nums.push_back(n);
            }
        }
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};
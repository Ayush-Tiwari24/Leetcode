class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0,end=0;
        int count=0;
        int ans=-1;
        unordered_map<int,int>m;
        
        while(end<fruits.size()){
            m[fruits[end]]++;
            if(m[fruits[end]]==1)
                count++;
            while(count>2){
                m[fruits[start]]--;
                if(m[fruits[start]]==0)
                    count--;
                start++;
            }
            if(count<=2)
                ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
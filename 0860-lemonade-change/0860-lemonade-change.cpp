class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        int total=0;
        int change=0;
        // sort(bills.begin(),bills.end());
        for(int i=0;i<bills.size();i++){
            change=bills[i]-5;
            if(change==5){
                if(m[5]>0){
                    m[5]--;
                    m[bills[i]]++;
                    continue;
                }
                else return false;
            }
            if(change==15){
                if(m[5]>=1 && m[10]>=1){
                    m[5]--;
                    m[10]--;
                }else if(m[5]>=3){
                    m[5]-=3;
                }else return false;
            }
            m[bills[i]]++;
        }
        return true;
    }
};
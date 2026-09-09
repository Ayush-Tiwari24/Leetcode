class Solution {
public:
    long long countCommas(long long n) {
        long long one,two,three,four,five;
        if(n<1000)return 0;
        one=n-999;
        two=n-999999;
        three=n-999999999;
        four=n-999999999999;
        five=n-999999999999999;
        long long ans;
        if(n<1000000){
            ans=one;
        }
        else if(n<1000000000){
            ans=one+two;
        }
        else if(n<1000000000000){
            ans=one+two+three;
        }
        else if(n<1000000000000000){
            ans=one+two+three+four;
        }
        else if(n<1000000000000000000){
            ans=one+two+three+four+five;
        }
        return ans;
    }
};
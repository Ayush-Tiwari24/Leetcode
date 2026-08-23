class Solution {
public:
    int digitSum(int sum,int n){
        if(n==0)return sum;
        return digitSum(sum+(n%10),n/10);
    }
    int digitMul(int mul,int n){
        if(n==0)return mul;
        return digitMul(mul*(n%10),n/10);
    }
    bool checkDivisibility(int n) {
        int sum=0;
        int mul=1;
        sum=digitSum(sum,n);
        mul=digitMul(mul,n);
        if(n%(sum+mul)==0)return true;
        return false;
    }
};
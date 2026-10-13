
class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;

        for(int i=0;i<s.size();i++){
            int x = s[i]-'a'+1;

            while(x>0){
                sum += x%10;
                x /= 10;
            }
        }
        k--;
        while(k>0){
            int temp=0;
            while(sum>0){
                temp += sum%10;
                sum /= 10;
            }
            sum=temp;
            k--;
        }
        return sum;
    }
};

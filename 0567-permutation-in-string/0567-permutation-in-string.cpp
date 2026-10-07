class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int k=s1.size();
       int n=s2.size();
       if(k>n)return false;
       string str="";
       sort(s1.begin(),s1.end());
       for(int i=0;i<k;i++){
            str+=s2[i];
       } 
       string nstr=str;
       sort(nstr.begin(),nstr.end());
       if(s1==nstr) return true;
       int j=0;
       for(int i=k;i<n;i++){
        str+=s2[i];
       str=str.substr(1);
        nstr=str;
        sort(nstr.begin(),nstr.end());
       if(s1==nstr) return true;
        j++;
       }
       return false;
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int maxm=INT_MAX;
        int start=0;
        string ans="";
        for(int i=0;i<n;i++){
            int a_1=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    a_1++;
                }
                if(a_1==k){
                    int len=j-i+1;
                    string curr=s.substr(i,len);
                    if(len<maxm){
                        maxm=len;
                        ans=curr;
                    }
                    else if(len==maxm&&curr<ans){
                        ans=curr;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

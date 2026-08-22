class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]-'0');
        }
        int prod=1;
        for(int i=0;i<s.size();i++){
            prod*=(s[i]-'0');
        }
        return (n%(sum+prod)==0);
    }
};

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<int>dp(n,0);
        dp[n-1]=prefix[n-1];
        for(int i=n-2;i>=1;i--){
            int pick=prefix[i]-dp[i+1];
            int notpick=dp[i+1];
            dp[i]=max(notpick,pick);
        }
        return dp[1];
    }
};

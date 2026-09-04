class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int maxm=nums[0];
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            maxm=max(maxm,nums[i]);
            int diff=maxm-suffix[i];
            ans=min(ans,diff);
            if(ans<=k){
                idx=i;
                break;
            }
        }
        return idx;
    }
};

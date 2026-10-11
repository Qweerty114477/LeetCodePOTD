class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>diff(1e5+1,0);
        for(int i=0;i<n;i++){
           int d=abs(nums1[i]-nums2[i]);
           diff[d]++; 
        }
        int k=k1+k2;
        for(int i=1e5;i>0&&k>0;i--){
            int ops=min(diff[i],k);
            diff[i]-=ops;
            diff[i-1]+=ops;
            k-=ops;
        }
        long long result=0;
        for(long long d=1;d<=1e5;d++){
            result+=(diff[d]*d*d);
        }
        return result;
    }
};

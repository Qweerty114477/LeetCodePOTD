class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int cntO=0,cntE=0;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++){
            if((nums1[i]&1)) cntO++;
        }

        cntE=n-cntO;
        if(cntE==n || cntO==n) return true;
        else {
            if((nums1[0]&1)) return true;
        }
        return false;
    }
};

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int i=2;
        int m=k;
        while(k<=200){
            if(!mpp.count(k)){
                return k;
            }
            k=m*i;
            i++;
        }
        return 0;
    }
};

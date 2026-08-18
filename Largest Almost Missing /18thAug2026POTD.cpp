class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int first=nums[0];
        int last=nums[n-1];
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        sort(nums.rbegin(),nums.rend());

        if(k==1){
            for(int i=0;i<n;i++){
                if(mpp[nums[i]]==1){
                    return nums[i];
                }
            }
        }
        if(k==n){
            return nums[0];
        }
        if(mpp[first]==1&&mpp[last]==1){
            return max(first,last);
        }
        else{
            if(mpp[first]==1) return first;
            else if(mpp[last]==1) return last;
            else if(first==last&&k==2&&n==2) return first;
            else return -1;
        }
        return 0;
    }
};

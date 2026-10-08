class Solution {
    public int minAddToMakeValid(String s) {
        int n=s.length();
        int ans=0;
        int ans1=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                ans++;
            }
            else {
                ans--;
                if(ans<0){
                    ans1++;
                    ans=0;
                }
            }
        }
        return ans+ans1;
    }
}

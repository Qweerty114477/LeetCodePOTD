class Solution {
    public int scoreOfParentheses(String s) {
        int n=s.length();
        int mrk=0, depth=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                depth++;
            }
            else {
                depth--;
                if(s.charAt(i-1)=='('){
                    mrk+=1<<depth;
                }
            }
        }
        return mrk;
    }
}

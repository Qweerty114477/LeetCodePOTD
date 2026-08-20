class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        unordered_map<int,unordered_set<int>>seats;
        for(auto it:reservedSeats){
            int row=it[0];
            int col=it[1];
            if(col>=2&&col<=5){
                seats[row].insert(0);
            }
            if(col>=4&&col<=7){
                seats[row].insert(1);
            }
            if(col>=6&&col<=9){
                seats[row].insert(2);
            }
        }
        int tot=2*n;
        for(auto [row,grp]:seats){
            if(grp.size()==3){
                tot-=2;
            }
            else {
                tot-=1;
            }
        }
        return tot;
    }
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size();
        int sr,sc;
        vector<pair<int,int>> litter;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    litter.push_back({i,j});
                }
            }
        }

        int k=litter.size();
        if(k==0) return 0;

        vector<vector<vector<int>>> best(
            m,vector<vector<int>>(n,vector<int>(1<<k,-1))
        );

        queue<tuple<int,int,int,int,int>> q;

        best[sr][sc][0]=energy;
        q.push({sr,sc,0,energy,0});

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            auto [r,c,mask,e,dist]=q.front();
            q.pop();

            if(mask==(1<<k)-1) return dist;

            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];

                if(nr<0||nr>=m||nc<0||nc>=n) continue;
                if(classroom[nr][nc]=='X') continue;
                if(e==0) continue;

                int ne=e-1;
                int nmask=mask;

                for(int i=0;i<k;i++){
                    if(litter[i].first==nr&&litter[i].second==nc){
                        nmask|=(1<<i);
                    }
                }

                if(classroom[nr][nc]=='R'){
                    ne=energy;
                }

                if(ne>best[nr][nc][nmask]){
                    best[nr][nc][nmask]=ne;
                    q.push({nr,nc,nmask,ne,dist+1});
                }
            }
        }

        return -1;
    }
};

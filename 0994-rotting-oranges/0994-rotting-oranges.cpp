class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> adj[n];
        queue<pair<int,int>> q;
        int fresh =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2 ){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }

            }

        }
        int min=0;
        vector<int> drow={0,-1,0,1};
        vector<int> dcol={-1,0,1,0};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){

            
            auto[row,col]=q.front();
            q.pop();


            for(int k=0;k<4;k++){
                int newr=row+drow[k];
                int newc=col+dcol[k];

                if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]==1){
                    grid[newr][newc]=2;
                    q.push({newr,newc});
                    fresh--;
                }
                }
                
            }
            min++;


        }
        return fresh==0?min:-1;
    }
};
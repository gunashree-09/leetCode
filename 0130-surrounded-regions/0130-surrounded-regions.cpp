class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                board[i][0]='G';
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                board[i][n-1]='G';
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                board[0][i]='G';
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                board[m-1][i]='G';
                q.push({m-1,i});
            }
        }

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=dr[k]+r;
                int nc=dc[k]+c;

                if(nr>=0 && nr<m && nc>= 0 && nc<n && board[nr][nc]=='O'){
                    board[nr][nc]='G';
                    q.push({nr,nc});

                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='G'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
    }
        }
    }
};
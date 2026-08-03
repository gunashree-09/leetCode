class Solution {
public:


    void solve(vector<vector<string>> &ans,
        vector<string>& board,int col,
        vector<int> &leftrow,vector<int> &upper,vector<int> &lower,int n){
   if(col==n){
    ans.push_back(board);
    return ;
   }

   for(int row=0;row<n;row++){
    if(leftrow[row]==0 && upper[n-1 +col-row]==0 && lower[row+col]==0){
        board[row][col]='Q';
        leftrow[row]=1;
        upper[n-1 +col-row]=1;
        lower[row+col]=1;
        solve(ans,board,col+1,leftrow,upper,lower,n);
        board[row][col]='.';
        leftrow[row]=0;
        upper[n-1 +col-row]=0;
        lower[row+col]=0;
    }
   }


        }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> leftrow(n,0),upper(2*n-1,0),lower(2*n-1,0);
        solve(ans,board,0,leftrow,upper,lower,n);
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        vector<int> v(n,0);
        q.push({sr,sc});
        int x=image[sr][sc];
        if(x==color) return image;
        image[sr][sc]=color;  
        vector<int> dr={0,0,1,-1};
        vector<int> dc={1,-1,0,0};
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto[r,c]=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int newr=r+dr[j];
                    int newc=c+dc[j];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==x){
                    image[newr][newc]=color;
                    q.push({newr,newc});
                }


                }
            }
        }
        return image;
    }
};
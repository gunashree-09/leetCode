class Solution {
public:
    bool dfs(int src, vector<int> adj[], vector<int>& vis,vector<int> & pvis,vector<int>& path) {
      vis[src] = 1; 
      pvis[src]=1;
      for(auto it: adj[src]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pvis,path)==true) return true;
        }
        else if(pvis[it]){
            return true;
        }

      }
      path.push_back(src);
      pvis[src]=0;
      return false; 
  }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto it: prerequisites){
            //adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> pvis(n,0);
        vector<int> vis(n,0);
        vector<int> path;
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis,pvis,path)) return {}; 
            }
        }
        reverse(path.begin(),path.end());
        return path; 

    }
};
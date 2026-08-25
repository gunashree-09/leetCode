class Solution {
public:
    bool dfs(int src, vector<int> adj[], vector<int>& vis,vector<int> & pvis) {
      vis[src] = 1; 
      pvis[src]=1;
      for(auto it: adj[src]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pvis)==true) return true;
        }
        else if(pvis[it]){
            return true;
        }

      }
      pvis[src]=0;
      return false; 
  }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto it: prerequisites){
            //adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> pvis(n,0);
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis,pvis)) return false; 
            }
        }
        return true; 

    }
};
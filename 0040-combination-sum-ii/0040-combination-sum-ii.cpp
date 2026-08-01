class Solution {
public:

  void solve(vector<int> &can,int & tar,vector<vector<int>> & res,int idx,int sum,vector<int>& curr){
        if(sum==tar){
            res.push_back(curr);
            return;}
        if(idx==can.size() || sum>tar) return ;
        
        
        curr.push_back(can[idx]);
        solve(can,tar,res,idx+1,sum+can[idx],curr);
        curr.pop_back();
        while(idx+1<can.size() && can[idx]==can[idx+1]){
            idx++;
        }
        solve(can,tar,res,idx+1,sum,curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates,target,res,0,0,curr);
        return res;
    }
};
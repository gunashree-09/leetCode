class Solution {
public:
    void solve(vector<int> &can,int & tar,vector<vector<int>> & res,int idx,int sum,vector<int>& curr){
        if(idx==can.size() || sum>tar) return ;
        if(sum==tar){
            res.push_back(curr);
            return;}
        
        curr.push_back(can[idx]);
        solve(can,tar,res,idx,sum+can[idx],curr);
        curr.pop_back();
        solve(can,tar,res,idx+1,sum,curr);
    }


     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates,target,res,0,0,curr);
        return res;
    }
};
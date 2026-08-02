class Solution {
public:
    void solve(int &k,int& tar,vector<vector<int>>& res,vector<int> & arr,int idx,int sum, vector<int>& cur){
if(idx==arr.size()) {
    if(cur.size()==k && sum==tar){
        res.push_back(cur);
    }
    return;
}
    cur.push_back(arr[idx]);
    solve(k,tar,res,arr,idx+1,sum+arr[idx],cur);
    cur.pop_back();
    solve(k,tar,res,arr,idx+1,sum,cur);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> curr;
        solve(k,n,res,arr,0,0,curr);
        return res;
    }
};
class Solution {
public:
   void solve(vector<int> & nums, vector<vector<int>> & res,vector<int>cur, int ind){
    if(nums.size()==ind){
        res.push_back(cur);
        return;
    }
    cur.push_back(nums[ind]);
    solve(nums,res,cur,ind+1);
    cur.pop_back();
    while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
        ind++;
    }
    solve(nums,res,cur,ind+1);
   }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,res,curr,0);
        return res; 
        
    }
};
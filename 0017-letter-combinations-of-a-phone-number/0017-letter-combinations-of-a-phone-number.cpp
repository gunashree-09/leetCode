class Solution {
public:
    void solve(string digits,map<char,string> & nums,vector<string>& res,int ind,string cur){
        if(ind==digits.length()){
                    res.push_back(cur);
                
         return ;}
         string s=nums[digits[ind]];
         for(char ch:s){
         solve(digits,nums,res,ind+1,cur+ch);}

    }
    vector<string> letterCombinations(string digits) {
        map<char,string> nums={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        solve(digits,nums,res,0,"");
        return res;
    }
};